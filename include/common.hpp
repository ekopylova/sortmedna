/*
 * SortMeDNA - metagenomic and genomic mapper for second and third generation sequencers
 * Copyright (C) 2015 Bonsai Bioinformatics Research Group
 *
 * This file is part of SortMeDNA.
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
 *
 * @authors jenya.kopylov@gmail.com (code, algo), laurent.noe@lifl.fr (code, algo)
 * helene.touzet@lifl.fr (algo), mikael.salson@lifl.fr (algo)
 *
 */

 /** @file common.hpp */

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sys/time.h>
#include <set>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>   // lseek
#include <fcntl.h>    // file checking, open/close
#include <sys/mman.h> 
#include <errno.h>

extern timeval t;

/*! @brief Macro for timing */
#define TIME(x) gettimeofday(&t, NULL); x = t.tv_sec + (t.tv_usec/1000000.0);

extern bool verbose;

/*! @brief Print function for verbose mode */
#define eprintf(format, ...) do { if (verbose) fprintf(stdout, format, ##__VA_ARGS__);} while(0)

// DEBUG: memory map
// output information during the splitting of 
// (output piped to stdout)
//#define debug_mmap

// DEBUG: seeds
// the Smith-Waterman alignment using the LIS 
// (output piped to stdout)
//#define debug_align

// DEBUG: LIS
// for constructing an LIS 
//#define debug_lis

// DEBUG: writing alignments to files
//#define debug_output

// DEBUG: binary burst trie
// output the writing of mini-burst tries into binary
// during indexdb_rna and also for reading from binary
// to re-construct the mini-burst tries in sortmerna 
// (both will be actived with this define statement).
// Will require C++11 compiler suppport, add -std=c++0x 
// to CXXFLAGS & CFLAGS in Makefile
// (piped to stdout)
//#define see_binary_output

// DEBUG: code to store the --best INT alignments
//#define DEBUG_BEST_N

/*! @brief Maximum length of input reads
	(not limited to this length algorithmically)
*/
#define READLEN 30000

/*! @brief Number of threads to launch */
extern int32_t numcpu_gv;

/*! @brief Verbose mode */
extern bool verbose;

/*! @brief Both reads are output to --aligned file

	If one of the paired reads aligns and the second
	does not (eg. the second read covers a hypervariable region),
	then put both reads into --aligned file
*/
extern bool pairedin_gv;

/*! @brief Both reads are output to --other file

	If one of the paired reads aligns and the second
	does not (eg. the second read covers a hypervariable region),
	then put both reads into --other file
*/
extern bool pairedout_gv;

/*! @brief Output log file */
extern bool logout_gv;

/*! @brief OTU-picking option: output candidate reads for 
	de novo clustering.

	Output reads (to FASTA/FASTQ file) that pass the E-value 
	threshold but have < %%id and < %%coverage scores for de 
	novo OTU-picking.
*/
extern bool de_novo_otu_gv;

/*! @brief Search forward strand */
extern bool forward_gv;

/*! @brief Search reverse strand */
extern bool reverse_gv;

/*! @brief OTU-picking option: output OTU map.

	Create an OTU map where each line:\n
		+ is tab-separated,\n
		+ the first column represents the OTU ID
		  (reference sequence ID),\n
		+ the remaining columns are read IDs
		  mapping to the reference ID with
		  E-value passing threshold, >= %id 
		  and >= %coverage scores.\n

	Example:\n
	ref_1 read_1 read_2 read_10\n
	ref_2 read_6 read_3
	..
*/
extern bool otumapout_gv;

/*! @brief Include process ID in output file names.

	Setting the flag --pid will append the master
	process ID to the output filenames (eg. --aligned
	and --other).
*/
extern bool pid_gv;

/*! @brief Size of partial section of reads file to mmap. */
extern long unsigned int map_size_gv;

/*! @brief SAM output. */
extern bool samout_gv;

/*! @brief Activate BLAST-like tabular output. */
extern bool blastout_gv;

/*! @brief Integer to store result from option --blast INT. 
	
	+ --blast 0: output pairwise alignments\n
	+ --blast 1: output classical BLAST tabular format,
			   the fields are:
			   queryId, subjectId, percIdentity, alnLength,
			   mismatchCount, gapOpenCount, queryStart, queryEnd,
			   subjectStart, subjectEnd, eVal, bitScore\n

	+ --blast 2: classical tabular format + column for CIGAR string\n
	+ --blast 3: classical tabular format + column for CIGAR string +
			   	 column for % query coverage
*/
extern int32_t blast_outfmt;

/*! @brief Activate FASTA/Q output. */
extern bool fastxout_gv;

/*! @brief Number of alignments to search based on the LIS 
	prior to outputting them.

	This illustration shows the behavior of using --min_lis INT
	to control the output of --best INT vs. using the option
	--num_alignments INT.

	The option --min_lis INT specifies the minimum number of
	references sequences having the longest LIS to search for
	alignments.

	As an example, choosing --best 2 --min_lis 2 will force
	the algorithm to search alignments for candidates
	ref #1, #2, #3, #4 and #5 prior to outputting the
	two best alignments (ref #1 and ref #3) for the read
	in this diagram. Candidate reference sequences are
	found using the LIS.

	@image html min_lis_small.png "Figure 1: Illustration of options --min_lis INT, --best INT and --num_alignments INT for SortMeRNA"
*/
extern int32_t min_lis_gv;

/*! @brief Number of best alignments per read to output */
extern int32_t num_best_hits_gv;

/*! @brief Number of alignments to output

	This option outputs the first --num_alignments INT
	alignments found, unlike --best INT which searches
	many alignments (specified by --min_lis INT) prior
	to outputting the best ones.
*/
extern int32_t num_alignments_gv;

/*! @brief Number of seed hits to find before searching 
	for candidate LIS.

	Prior to alignment, SortMeRNA searches for short k-mers 
	(default length 18) between the read and the reference
	database. This option sets the minimum number of k-mer
	matches required in order to continue to the next step
	of searching for the LIS.
*/
extern int32_t seed_hits_gv;

/*! @brief Number or percent (if followed by %) of nucleotides 
	to add to each edge of the alignment region prior to SSW 
	extension.

	SortMeRNA uses the LIS to find candidate regions between
	reference sequences and the read for performing
	Smith-Waterman alignment. This option allows
	to add nucleotides to both ends of the reference
	sequence region where alignment will be carried out,
	to allow for extra insertions & deletions.
*/
extern int32_t edges_gv;

/*! @brief Interpret option --edges as percent */
extern bool as_percent_gv;

/*! @brief Flag to turn off heuristic for stopping index 
	search after finding a 0-error match, instead collect 
	all 0-error and 1-error matches.
*/
extern bool full_search_gv;

/*! @brief E-value threshold */
extern double evalue;

/*! @brief OTU-picking option: minimum %%id to keep alignment */
extern double align_id;

/*! @brief OTU-picking option: minimum %%coverage to keep alignment */
extern double align_cov;

/*! @brief If true, print all reads in SAM and/or BLAST 
	output (aligned and non-aligned)
*/
extern bool print_all_reads_gv;

#endif

