#!/bin/bash

FILE="employees.txt"

echo "Task 1: Basic Field Extraction"

awk -F, '{print $1, $2}' $FILE


echo ""
echo "Task 2: Engineering Employees"

awk -F, '$2=="Engineering" {print}' $FILE


echo ""
echo "Task 3: Gross Pay Calculation"

awk -F, '{print $1 " gross pay: $" $3*$4}' $FILE


echo ""
echo "Task 4: NR and NF"

awk -F, '{print NR " (" NF " fields): " $0}' $FILE


echo ""
echo "Task 5: Engineering Payroll"

awk -F, '
BEGIN {
    total=0
}

$2=="Engineering" {
    total += $3*$4
}

END {
    print "Total Engineering Payroll: $" total
}
' $FILE
