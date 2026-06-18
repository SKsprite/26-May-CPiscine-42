if [ -z "$1" ]
then
	echo "No file path provided"
else
	failed_count=0
	for dir in ex*/
	do
		mkdir -p "$1/$dir" 2> /dev/null
		cp "./${dir}test.c" "$1/${dir}test.c" 2> /dev/null
		if [ $? -eq 0 ]
		then
			echo "SUCCESS: Copied ./${dir}test.c to $1/${dir}test.c"
		else
			echo "FAILED: Could not copy ./{$dir}test.c"
			(($failed_count++))
		fi
	done

	echo "--------------------"
	if [ $failed_count -eq 0 ]
	then
		echo "OVERALL STATUS: ALL COPIES SUCCESSFUL"
	else
		ehco "OVERALL STATUS: ($failed_count copy operations failed)"
	fi
fi
