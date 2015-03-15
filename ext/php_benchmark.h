
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BENCHMARK_H
#define PHP_BENCHMARK_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_BENCHMARK_NAME        "benchmark"
#define PHP_BENCHMARK_VERSION     "0.0.1"
#define PHP_BENCHMARK_EXTNAME     "benchmark"
#define PHP_BENCHMARK_AUTHOR      ""
#define PHP_BENCHMARK_ZEPVERSION  "0.6.0a"
#define PHP_BENCHMARK_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(benchmark)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(benchmark)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(benchmark)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(benchmark_globals_id, zend_benchmark_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (benchmark_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_benchmark_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(benchmark_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(benchmark_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def benchmark_globals
#define zend_zephir_globals_def zend_benchmark_globals

extern zend_module_entry benchmark_module_entry;
#define phpext_benchmark_ptr &benchmark_module_entry

#endif
