#include <stdio.h>
#include <stdlib.h>
#define TAM_DISK 1474560
#define ARCHIVO_SALIDA "disk.dsk"

long lFileLength(FILE *psfF)
{
  long lRet;
  fseek(psfF, 0L, SEEK_END);
  lRet = ftell(psfF);
  fseek(psfF, 0L, SEEK_SET);
  return (lRet);
}

int main(int iArgs, char *pscArgs[])
{
  unsigned char *pcD;
  FILE *psfIn;
  long lTam, i;
  if (iArgs != 2)
  {
    printf("Falta archivo de entrada.\n");
    exit(1);
  }
  pcD = (unsigned char *)malloc(TAM_DISK);
  if (!pcD)
  {
    printf("No hay memoria.\n");
    exit(2);
  }
  for (i = 0; i < TAM_DISK; i++)
    pcD[i] = 0;
  psfIn = fopen(pscArgs[1], "rb");
  if (!psfIn)
  {
    printf("Error al abrir %s\n", pscArgs[1]);
    free(pcD);
    exit(3);
  }
  lTam = lFileLength(psfIn);
  fread(pcD, 1, lTam, psfIn);
  fclose(psfIn);
  psfIn = fopen(ARCHIVO_SALIDA, "wb");
  if (!psfIn)
  {
    printf("Error al crear %s\n", ARCHIVO_SALIDA);
    free(pcD);
    exit(4);
  }
  fwrite(pcD, 1, TAM_DISK, psfIn);
  fclose(psfIn);
  free(pcD);
  return (0);
}