 /**
 * @brief Header file for bitvector.cpp
 * @parblock
 * SortMeDNA - metagenomic and genomic mapper for second and third generation sequencers
 * @copyright 2013-2015 Bonsai Bioinformatics Research Group
 * 2015 Knight Lab, Department of Pediatrics, UCSD, La Jolla
 * GNU GENERAL PUBLIC LICENSE
 *
 * SortMeDNA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SortMeDNA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with SortMeDNA.  If not, see <http://www.gnu.org/licenses/>.
 * @endparblock
 *
 * authors: Jenya Kopylova jenya.kopylov@gmail.com
 *          Laurent Noé    laurent.noe@lifl.fr
 *          Mikaël Salson  mikael.salson@lifl.fr
 *          Rob Knight     robknight@ucsd.edu
 *          Hélène Touzet  helene.touzet@lifl.fr
 */

 /** @file bitvector.hpp */

#ifndef BITVECTOR_H
#define BITVECTOR_H

#include "indexdb.hpp" 				 /* for map matrix */

#define MYBITSET unsigned char     /* a bitvector of 1 byte */

/* mask for depth > 0 bitvectors for k = 1 */
#define MSB4 (MYBITSET)4

/* mask for depth = 0 bitvectors for k = 1 */
#define MSB8 (MYBITSET)8	


/* initialized in paralleltraversal.cpp */
extern int _win_num;
extern int thiswindow;
extern int _readn;
extern int thisread;




/*
 *
 * FUNCTION 	: void init_win_k1   ( char*, MYBITSET*, MYBITSET* )
 * PURPOSE	: create the first bitvector table of the 17-mer window on the read at position i = 0.
 * PARAMETERS	: 	  
 *
 **************************************************************************************************************/
void init_win_f   ( char*, MYBITSET*, MYBITSET*, int numbvs );
void init_win_r   ( char*, MYBITSET*, MYBITSET*, int numbvs );



/*
 *
 * FUNCTION 	: void offset_win_k1 ( char*, char*, MYBITSET*, MYBITSET*, MYBITSET* )
 * PURPOSE	: for each 17-mer window after the first one on the read, the bitvector table is
 *		  computed from the previous one by means of bitshifting and looking only at the new character
 *		  of the read
 * PARAMETERS	: 
 *		  	  
 *
 **************************************************************************************************************/
void offset_win_k1 ( char*, char*, MYBITSET*, MYBITSET*, MYBITSET*, int numbvs );



/*
 *
 * FUNCTION 	: void output_win_k1 ( MYBITSET*, bool )
 * PURPOSE	: output the bitvector table (for debugging)
 * PARAMETERS	: 	  
 *
 **************************************************************************************************************/
void output_win_k1 ( MYBITSET*, bool, int partialwin );

#endif 
