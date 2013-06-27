#include <stdio.h>
#include <stdint.h> 

#define OFFSET_TO_BOOTSTREAM 1024

typedef struct _ssp_clockConfig
{
    int    clkSel   :1; //!< Clock Select (0=io_ref 1=xtal_ref)
    int    io_frac   :6; //!< IO FRAC 18-35 (io_frac+16)
    int    ssp_frac   :9; //!< SSP FRAC (1=default)
    int    ssp_div   :8; //!< Divider: Must be an even value 2-254
    int    ssp_rate   :8; //!< Serial Clock Rate
} ssp_ClockConfig_t;


typedef struct _spi_ConfigBlockFlags
{
    uint32_t DisableFastRead:1; // Ignored for Spis
                                 // 0 - Do not disable fast reads
                                 // 1 - Disable fast reads
} spi_ConfigBlockFlags_t;

typedef struct _spi_ConfigBlockClocks
{
    uint32_t           SizeOfSspClockConfig; // sizeof(ssp_ClockConfig_t)
    ssp_ClockConfig_t SspClockConfig;        // SSP clock configuration structure. A null
                                             //   structure indicates no clock change.
} spi_ConfigBlockClocks_t;

typedef struct _spi_ConfigBlock // Little Endian
{
    uint32_t  Signature;            // 0x4D454D53, or "SMEM"
    uint32_t  BootStartAddr;        // Start address of boot image. Must be >=
                                    //   sizeof(spi_ConfigBlock_t)
    uint32_t  SectorSize;           // Sector size in bytes. Overrides ROM default
                                    //   of 128-bytes. Max is 1024-bytes. 0 is
                                    //   default 128-bytes.
    spi_ConfigBlockFlags_t Flags;   // Various flags. See spi_ConfigBlockFlags
    spi_ConfigBlockClocks_t Clocks; // SCK clock update structure.
} spi_ConfigBlock_t ;




int main(int argc, char *argv[]) {
   
   FILE *infile, *outfile;
   
   spi_ConfigBlock_t cb = {
     .Signature = 0x4D454D53,
     .BootStartAddr = OFFSET_TO_BOOTSTREAM, 
     .SectorSize = 0,
     {
        .DisableFastRead = 0,
     },
     {
       .SizeOfSspClockConfig = sizeof(ssp_ClockConfig_t),
       .SspClockConfig = {
          .clkSel = 0,
          .io_frac = 21,
          .ssp_frac = 4,
          .ssp_div = 2,
          .ssp_rate = 0,
       }
     },
   } ;
    
   if (argc < 3) {    
      printf("usage spi-build inputfile outputfile\n");
      return 1;
   }
   
   infile = fopen(argv[1], "r");
   if (infile) {
      outfile = fopen(argv[2], "w");
   
      if (outfile) {
         int i, tot;
         unsigned short us;
         unsigned char *cp, x[2];
                   
         tot = 0;
         cp = (unsigned char *)&cb; 
         
         for(i=0; i < sizeof(cb); i+=2) {
            x[1] = *cp++;
            x[0] = *cp++;
            
            fwrite(&x, 2, 1, outfile);
            tot += 2;
         }
         
         while (i++ < OFFSET_TO_BOOTSTREAM) {
            fputc(0xFF, outfile);
            tot++;
         }
                                       
         while(1) {
          us = 0xFFFF;  
          i = fread(&us, sizeof(us), 1, infile);  
          if (i <= 0) break;
                    
          cp = (unsigned char *)&us;
          x[0] = cp[1];
          x[1] = cp[0];
          fwrite(&x, sizeof(x), 1, outfile);
          tot += sizeof(x);
         }
         
         while(tot % 512) {          
            fputc(0xFF, outfile);
            tot++;
         }
         
         fclose(outfile);  
         
         printf("spi-build:  output '%s' is %d bytes\n", argv[2], tot);
         
      } else {
         printf("Can't open output file '%s'\n", argv[2]);
         return 1;
      }
   } else {
         printf("Can't open input file\n");
         return 1;
      }
   
   return 0;
}
