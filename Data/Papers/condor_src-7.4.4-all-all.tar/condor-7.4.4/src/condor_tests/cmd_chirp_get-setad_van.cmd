universe = vanilla
executable = cmd_chirp_get-setad_van.pl
input = 
output = cmd_chirp_get-setad_van.out
error = cmd_chirp_get-setad_van.err
notification = never
log = cmd_chirp_get-setad_van.log 
transfer_input_files = ../release_dir/libexec/condor_chirp 

should_transfer_files = YES
when_to_transfer_output = ON_EXIT_OR_EVICT
+WantIOProxy = true

queue
