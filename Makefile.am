# Makefile.am

# bin are installed by default in /usr/local/bin/
bin_PROGRAMS       = indexdb_dna sortmedna

include_HEADERS    = ./alp/gumbel_params.hpp ./alp/njn_dynprogprob.hpp ./alp/njn_dynprogproblim.hpp ./alp/njn_dynprogprobproto.hpp ./alp/njn_ioutil.hpp ./alp/njn_localmaxstat.hpp ./alp/njn_localmaxstatmatrix.hpp ./alp/njn_localmaxstatutil.hpp ./alp/njn_random.hpp ./alp/sls_alp.hpp ./alp/sls_alp_data.hpp ./alp/sls_alp_regression.hpp ./alp/sls_alp_sim.hpp ./alp/sls_pvalues.hpp \
                     ./alp/gumbel_params.hpp ./alp/njn_approx.hpp ./alp/njn_doubletype.hpp ./alp/njn_dynprogprob.hpp ./alp/njn_dynprogproblim.hpp ./alp/njn_dynprogprobproto.hpp ./alp/njn_function.hpp ./alp/njn_integer.hpp ./alp/njn_ioutil.hpp ./alp/njn_localmaxstat.hpp ./alp/njn_localmaxstatmatrix.hpp ./alp/njn_localmaxstatutil.hpp ./alp/njn_matrix.hpp ./alp/njn_memutil.hpp ./alp/njn_random.hpp ./alp/njn_root.hpp ./alp/njn_stringutil.hpp ./alp/njn_uniform.hpp ./alp/njn_vector.hpp ./alp/sls_alp.hpp ./alp/sls_alp_data.hpp ./alp/sls_alp_regression.hpp ./alp/sls_alp_sim.hpp ./alp/sls_normal_distr_array.hpp ./alp/sls_pvalues.hpp \
                     ./cmph/bdz.h ./cmph/bdz_ph.h ./cmph/bdz_structs.h ./cmph/bdz_structs_ph.h ./cmph/bitbool.h ./cmph/bmz.h ./cmph/bmz8.h ./cmph/bmz8_structs.h ./cmph/bmz_structs.h ./cmph/brz.h ./cmph/brz_structs.h ./cmph/buffer_entry.h ./cmph/buffer_manager.h ./cmph/chd.h ./cmph/chd_ph.h ./cmph/chd_structs.h ./cmph/chd_structs_ph.h ./cmph/chm.h ./cmph/chm_structs.h ./cmph/cmph.h ./cmph/cmph_structs.h ./cmph/cmph_time.h ./cmph/cmph_types.h ./cmph/compressed_rank.h ./cmph/compressed_seq.h ./cmph/debug.h ./cmph/fch.h ./cmph/fch_buckets.h ./cmph/fch_structs.h ./cmph/graph.h ./cmph/hash.h ./cmph/hash_state.h ./cmph/jenkins_hash.h ./cmph/miller_rabin.h ./cmph/select.h ./cmph/select_lookup_tables.h ./cmph/vqueue.h ./cmph/vstack.h \
                     ./include/bitvector.hpp ./include/common.hpp ./include/indexdb.hpp ./include/paralleltraversal.hpp ./include/ssw.h ./include/outputformats.hpp

indexdb_dna_SOURCES    = ./cmph/bdz.c ./cmph/bdz_ph.c ./cmph/bmz.c ./cmph/bmz8.c ./cmph/brz.c ./cmph/buffer_entry.c ./cmph/buffer_manager.c ./cmph/chd.c ./cmph/chd_ph.c ./cmph/chm.c ./cmph/cmph.c ./cmph/cmph_structs.c ./cmph/compressed_rank.c ./cmph/compressed_seq.c ./cmph/fch.c ./cmph/fch_buckets.c ./cmph/graph.c ./cmph/hash.c ./cmph/jenkins_hash.c ./cmph/miller_rabin.c ./cmph/select.c ./cmph/vqueue.c ./cmph/vstack.c \
	             ./src/indexdb.cpp

sortmedna_SOURCES  = ./alp/gumbel_params.cpp ./alp/njn_dynprogprob.cpp ./alp/njn_dynprogproblim.cpp ./alp/njn_dynprogprobproto.cpp  ./alp/njn_ioutil.cpp ./alp/njn_localmaxstat.cpp ./alp/njn_localmaxstatmatrix.cpp ./alp/njn_localmaxstatutil.cpp ./alp/njn_random.cpp ./alp/sls_alp.cpp ./alp/sls_alp_data.cpp ./alp/sls_alp_regression.cpp ./alp/sls_alp_sim.cpp ./alp/sls_pvalues.cpp \
                     ./src/bitvector.cpp ./src/ssw.c ./src/outputformats.cpp ./src/paralleltraversal.cpp ./src/main.cpp


check: check-am
	@echo ' '
	@echo '---------------------------------------------------------------------------------------------'
	@echo 'Todo ... '
	@echo '---------------------------------------------------------------------------------------------'
	@echo ' '


install: install-am
	@echo ' '
	@echo '---------------------------------------------------------------------------------------------'
	@echo 'Todo ... '
	@echo '---------------------------------------------------------------------------------------------'
	@echo ' '

installcheck: installcheck-am
	@echo ' '
	@echo '---------------------------------------------------------------------------------'
	@echo 'Todo ... '
	@echo '---------------------------------------------------------------------------------'
	@echo ' '


uninstall: uninstall-am
	cd $(prefix)/@PACKAGE@/index && rm *

