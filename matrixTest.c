/*
 * =====================================================================================
 *
 *       Filename:  matrixTest.c
 *
 *    Description:  matrix test for library Meschach
 *
 *        Version:  1.0
 *        Created:  01/02/18 23:23:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Myoungki Jung (mj), myoungki.jung@gmail.com
 *   Organization:  Lunarpulse
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include <math.h>
#include "matrix2.h"
#include "zmatrix.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ArTOMat
 *  Description:  
 * =====================================================================================
 */
	void
ArToMat ( void* data, MAT* mat, int m, int n )
{
	float* arr = (float*)data;
	for ( int i = 0; i< m ;++i )
	{

		for ( int j = 0;j< n ;++j )
		{

		    mat->me[i][j] = arr[i*m+j];
		}
	}
	return; 
}		/* -----  end of function ArToMat  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main (int argc, char *argv[])
{

  MAT *m, *m_inv;
  m = m_get (3, 3);
  PERM *pm;
  pm = px_get (10);

  float ar[3][3]= {{1.0f,0.6f,0.0f},{0.0f,1.5f,1.0},{0.0f,1.0f,1.0f}};
 
  ArToMat((void*)ar, m, 3,3);
  
  m_output(m);
  m_inv = m_get(3,3);
  m_inverse(m,m_inv);

  m_output(m_inv);

  pm->pe[0]= 10;
  pm->pe[1]=40;
  pm->pe[2]=20;

  M_FREE(m);
  M_FREE(m_inv);

  px_output(pm);
  
  PERM *pm_inv;
  pm_inv = px_get(10);

  px_ident(pm_inv);
  printf("pm_indent:\n");
  px_output(pm_inv);
  px_transp(pm_inv, 3, 5);
  printf("pm_transp:\n");
  px_output(pm_inv);

  px_inv(pm_inv, pm_inv);
  printf("pm_inv:\n");
  px_output(pm_inv);

  PERM* pmr;
  pmr = px_get(10);
  px_mlt(pm,pm_inv,pmr);
  printf("pmr:\n");
  px_output(pmr);

  PX_FREE(pm);
  PX_FREE(pm_inv);
  PX_FREE(pmr);

  ZMAT *ZM;
  complex zc;
  zc.re = 2.3f;
  zc.im = -9.2f;

  ZM = zm_get(10,10);
  ZM->me[2][3] = zc;

  printf("real part = %g, imaginary part = %g\n",
		  ZM->me[2][3].re, ZM->me[2][3].im);
  ZM_FREE(ZM);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
