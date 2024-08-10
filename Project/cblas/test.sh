#!/bin/zsh
if [ $# -ne 3 ]; then  
    echo "Usage: $0 <size> <num_tests> <if_test>"  
    exit 1  
fi  

size=$1  
num_tests=$2
iftest=$3
echo "Size: $size" > output_bentch_mark
echo "Number of tests: $num_tests" >> output_bentch_mark
echo "Size: $size" > output_main
echo "Number of tests: $num_tests" >> output_main
echo "Size: $size" > output_str
echo "Number of tests: $num_tests" >> output_str

for ((i=0; i<$num_tests; i++))  
do  
    ./rand_mat $size $size > input  
    ./rand_mat $size $size >> input  
    ./bentch_mark $iftest < input >> output_bentch_mark
    ./main $iftest < input >> output_main
    ./strassen $iftest < input >> output_str
done  

if [ $3 -eq 0 ]; then
    echo "Bentch_mark: " > output_analysis
    ./analysis < output_bentch_mark >> output_analysis
    echo "Main: " >> output_analysis
    ./analysis < output_main >> output_analysis
    echo "Strassen: " >> output_analysis
    ./analysis < output_str >> output_analysis
fi
