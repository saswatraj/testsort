tavg=0
for (( i=0 ; i<=$1; i++ ))
do
	a=$(./quick $2 2>&1)
	tavg=$(( $a + $tavg ))
done
tavg=$(( $tavg / $1 ))
echo $tavg
