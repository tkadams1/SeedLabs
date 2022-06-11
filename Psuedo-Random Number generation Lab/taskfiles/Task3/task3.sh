while true
do
	cat /proc/sys/kernel/random/entropy_avail | tee -a task3outputmouse.txt
	sleep 1
done


