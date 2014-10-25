# We need THREE files which are each as big as main memory (assuming 64m).

setenv disk1 	/export/home/bil/junk/time_disk1.tmp
setenv disk2 	/disk2/6/bil/junk/time_disk2.tmp
setenv clear 	/disk2/6/bil/junk/clear_disk.tmp


ln -s $clear	/tmp/clear_disk.tmp
ln -s $disk1	/tmp/time_disk1.tmp
ln -s $disk2	/tmp/time_disk2.tmp

touch 	/tmp/time_disk2.tmp
touch 	/tmp/time_disk1.tmp
touch   /tmp/clear_disk.tmp

# 63 chars
echo "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" >> /tmp/time_disk1.tmp

# 6300 chars
repeat 100 cat /tmp/time_disk1.tmp >> /tmp/time_disk2.tmp

# 630,000 chars
repeat 100 cat /tmp/time_disk2.tmp >> /tmp/time_disk1.tmp


# 63,000,000 chars
repeat 100 cat /tmp/time_disk1.tmp >> /tmp/time_disk2.tmp

# 63,630,000 chars
cat /tmp/time_disk2.tmp >> /tmp/time_disk1.tmp

# 63,000,000 chars
cat /tmp/time_disk2.tmp >> /tmp/clear_disk.tmp


#clean rm /tmp/clear_disk.tmp /tmp/time_disk1.tmp /tmp/time_disk2.tmp $disk1 $disk2 $clear
