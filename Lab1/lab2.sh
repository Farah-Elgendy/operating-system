#! /bin/bash

src=$1
dst=$2
time=$3
max=$4
n=$#
if [ ! -d $src ]
then
	echo "This directory doesn't exist"
	exit 
elif [ $n -ne 4 ]
then
	echo "Enter 4 parameters only"
	exit
elif ! [[ $time =~ ^[0-9]+$ ]] || ! [[ $max =~ ^[0-9]+$ ]]
then
	echo "Enter a valid parameters"
	exit
fi	 
ls -lR $src > dir-info.last
cp -r $src $dst/"$(date +"%y-%m-%d-%T")"
count=1
while : 
do
  sleep $time
  ls -lR $src > dir-info.new
  if cmp -s "dir-info.last" "dir-info.new"
  then
      echo "No change"
  else 
      count=$(($count+1))
      if [ $count -gt $max ]
      then
          d=$(ls $dst | head -1)
          rm -rf `find $dst -type d -name $d`
          echo "deleted"
      fi
      cp -r $src $dst/"$(date +"%y-%m-%d-%T")"
      ls -lR $src > dir-info.last
      echo "there is a change"
      
  fi
done
