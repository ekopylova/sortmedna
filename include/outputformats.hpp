 /**
 * @brief Header file for outputformats.cpp
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

/** @file outputformats.hpp */ 
 
#ifndef OUTPUTFORMATS_H
#define OUTPUTFORMATS_H

#include <istream>

//! SIMD Smith-Waterman alignment library
#include "ssw.h"
#include "indexdb.hpp"

using namespace std;

void report_blast (ofstream &fileout,
                   s_align* a,
                   char* read_name,
                   char* read_seq,
                   char* read_qual,
                   char* ref_name,
                   char* ref_seq,
                   double evalue,
                   uint32_t readlen,
                   uint32_t bitscore,
                   bool strand,
                   double id,
                   double coverage,
                   uint32_t mismatches,
                   uint32_t gaps);


void report_sam (ofstream &fileout,
                 s_align* a,
                 char* read_name,
                 char* read_seq,
                 char* read_qual,
                 char* ref_name,
                 char* ref_seq,
                 uint32_t readlen,
                 bool strand,
                 uint32_t diff);

void report_fasta (char* acceptedstrings,
                   char* ptr_filetype_or,
                   char* ptr_filetype_ar,
                   char** reads,
                   int32_t strs,
                   vector<bool>& read_hits,
                   uint32_t file_s,
                   char* finalnt);

void report_denovo(char *denovo_otus_file,
                   char **reads,
                   int32_t strs,
                   vector<bool>& read_hits_denovo,
                   uint32_t file_s,
                   char *finalnt);

void report_biom (char* biomfile);

#endif