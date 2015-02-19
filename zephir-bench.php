<?php
/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */

ini_set('display_errors', 1);
ini_set('memory_limit', '2048M');
gc_disable();

\Benchmark\Benchmark::bench();