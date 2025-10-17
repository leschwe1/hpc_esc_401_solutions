
#!/bin/bash

#Write a simple bash (or python) script which goes through each
#measurement_*.txt. Extract the data of TEMPERATURE and TIME (so humidity data are
#skipped) from all files and store it in a single file out.txt. In addition, the script should print
#the average measured temperature. Note there are also other files in the directory measured,
#which are irrelevant for this task. Make sure to skip them in your script.
#Hint: Use a regular expression that matches the lines with temperature and time. Furthermore, bash is not able to do floating point arithmetic but you can use the program bc for
#calculations.


#extract temperature and time
n=1

sum=0
count=0

output_file="solution_task2.txt"
> "$output_file" #ensure clear

for i in {1..5}; do
    name="measurements$i.txt"
    echo "checking file  $name"

    while read -r line; do                                # read lines with temperature, not humidity
        echo "$line" >> "$output_file"                    # put the line to new file
        temp=$(echo "$line" | awk '{print $2}')           # parse the second item of a line
        sum=$(echo "$sum + $temp" | bc)                   # add temp to sum
        count=$((count + 1))                              # count +1
    done < <(grep "^Temperature" "$name")                 
done

if [ "$count" -gt 0 ]; then                               # check if any values
    avg=$(echo "scale=2; $sum / $count" | bc)             # calc average
    echo "Average temperature: $avg"                      # return
    echo "Average temperature: $avg" >> "$output_file"
else    
    echo "No temperature data found."
    echo "No temperature data found." >> "$output_file"
fi
