# 
#  

echo "Run this, then edit create_all.csh to set the correct order,"
echo "then csh create_all.csh"
echo; echo;

test -f scripts/create_all.csh && mv scripts/create_all.csh  scripts/create_all.csh.old


echo "rm */all" > scripts/create_all.csh
echo "echo; echo" >> scripts/create_all.csh

foreach dir (*)
  setenv dirp 0
  test -d $dir && setenv dirp 1
  if ($dirp) then
      echo "starting $dir/all"
      echo "touch $dir/all" >> scripts/create_all.csh
      echo echo \"//	\`date\`\" ">>" $dir/all  >> scripts/create_all.csh
      foreach file ($dir/*.java $dir/*.c $dir/*.csh $dir/*.h)
          echo "cat $file >> $dir/all" >> scripts/create_all.csh
          echo "cat scripts/empty_space >> $dir/all" >> scripts/create_all.csh
      end
  endif
  echo "" >> scripts/create_all.csh
end
