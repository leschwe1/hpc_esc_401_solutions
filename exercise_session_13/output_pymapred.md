./pymapred.sh
packageJobJar: [/tmp/hadoop-unjar7507426507842156735/] [] /tmp/streamjob10073121427770448758.jar tmpDir=null
2025-12-18 10:53:17,562 INFO client.DefaultNoHARMFailoverProxyProvider: Connecting to ResourceManager at localhost/127.0.0.1:8032
2025-12-18 10:53:17,689 INFO client.DefaultNoHARMFailoverProxyProvider: Connecting to ResourceManager at localhost/127.0.0.1:8032
2025-12-18 10:53:18,249 INFO mapreduce.JobResourceUploader: Disabling Erasure Coding for path: /tmp/hadoop-yarn/staging/ubuntu/.staging/job_1766052885666_0001
2025-12-18 10:53:20,639 INFO mapred.FileInputFormat: Total input files to process : 7
2025-12-18 10:53:21,846 INFO mapreduce.JobSubmitter: number of splits:7
2025-12-18 10:53:23,192 INFO mapreduce.JobSubmitter: Submitting tokens for job: job_1766052885666_0001
2025-12-18 10:53:23,192 INFO mapreduce.JobSubmitter: Executing with tokens: []
2025-12-18 10:53:23,499 INFO conf.Configuration: resource-types.xml not found
2025-12-18 10:53:23,499 INFO resource.ResourceUtils: Unable to find 'resource-types.xml'.
2025-12-18 10:53:23,861 INFO impl.YarnClientImpl: Submitted application application_1766052885666_0001
2025-12-18 10:53:23,894 INFO mapreduce.Job: The url to track the job: http://hadoop-leschwe.cloud.science-it.uzh.ch:8088/proxy/application_1766052885666_0001/
2025-12-18 10:53:23,895 INFO mapreduce.Job: Running job: job_1766052885666_0001
2025-12-18 10:53:31,976 INFO mapreduce.Job: Job job_1766052885666_0001 running in uber mode : false
2025-12-18 10:53:31,976 INFO mapreduce.Job:  map 0% reduce 0%
2025-12-18 10:53:42,080 INFO mapreduce.Job:  map 14% reduce 0%
2025-12-18 10:53:46,100 INFO mapreduce.Job:  map 29% reduce 0%
2025-12-18 10:53:48,117 INFO mapreduce.Job:  map 43% reduce 0%
2025-12-18 10:53:51,131 INFO mapreduce.Job:  map 71% reduce 0%
2025-12-18 10:53:52,135 INFO mapreduce.Job:  map 86% reduce 0%
2025-12-18 10:53:54,148 INFO mapreduce.Job:  map 100% reduce 0%
2025-12-18 10:53:56,160 INFO mapreduce.Job:  map 100% reduce 100%
2025-12-18 10:53:58,173 INFO mapreduce.Job: Job job_1766052885666_0001 completed successfully
2025-12-18 10:53:58,248 INFO mapreduce.Job: Counters: 55
        File System Counters
                FILE: Number of bytes read=5550040
                FILE: Number of bytes written=13348613
                FILE: Number of read operations=0
                FILE: Number of large read operations=0
                FILE: Number of write operations=0
                HDFS: Number of bytes read=12914644
                HDFS: Number of bytes written=642476
                HDFS: Number of read operations=26
                HDFS: Number of large read operations=0
                HDFS: Number of write operations=2
                HDFS: Number of bytes read erasure-coded=0
        Job Counters 
                Killed map tasks=1
                Launched map tasks=7
                Launched reduce tasks=1
                Rack-local map tasks=7
                Total time spent by all maps in occupied slots (ms)=77489
                Total time spent by all reduces in occupied slots (ms)=9727
                Total time spent by all map tasks (ms)=77489
                Total time spent by all reduce tasks (ms)=9727
                Total vcore-milliseconds taken by all map tasks=77489
                Total vcore-milliseconds taken by all reduce tasks=9727
                Total megabyte-milliseconds taken by all map tasks=79348736
                Total megabyte-milliseconds taken by all reduce tasks=9960448
        Map-Reduce Framework
                Map input records=35371
                Map output records=538568
                Map output bytes=4472896
                Map output materialized bytes=5550076
                Input split bytes=819
                Combine input records=0
                Combine output records=0
                Reduce input groups=47090
                Reduce shuffle bytes=5550076
                Reduce input records=538568
                Reduce output records=47090
                Spilled Records=1077136
                Shuffled Maps =7
                Failed Shuffles=0
                Merged Map outputs=7
                GC time elapsed (ms)=589
                CPU time spent (ms)=8910
                Physical memory (bytes) snapshot=2266890240
                Virtual memory (bytes) snapshot=21925838848
                Total committed heap usage (bytes)=1798307840
                Peak Map Physical memory (bytes)=324800512
                Peak Map Virtual memory (bytes)=2756923392
                Peak Reduce Physical memory (bytes)=217571328
                Peak Reduce Virtual memory (bytes)=2745483264
        Shuffle Errors
                BAD_ID=0
                CONNECTION=0
                IO_ERROR=0
                WRONG_LENGTH=0
                WRONG_MAP=0
                WRONG_REDUCE=0
        File Input Format Counters 
                Bytes Read=12913825
        File Output Format Counters 
                Bytes Written=642476
2025-12-18 10:53:58,248 INFO streaming.StreamJob: Output directory: output
