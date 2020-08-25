#! /bin/bash

# This is a script to analyse recoder
# Author : hxu
# Data   : 2020-8-24

######            1.   simplify recoder           ######
i=1
sed 's/"mode"://g' test.txt >| temp_$i.log
sed 's/,//g' temp_$i.log >| temp_$[i+1].log
sed 's/"src_format"://g' temp_$[i+1].log >| temp_$[i+2].log
sed 's/"src_w"://g' temp_$[i+2].log >| temp_$[i+3].log
sed 's/"//g' temp_$[i+3].log >| temp_$[i+4].log
sed 's/src_h//g' temp_$[i+4].log >| temp_$[i+5].log
sed 's/src_line_stride://g' temp_$[i+5].log >| temp_$[i+6].log 
sed 's/dst_format//g' temp_$[i+6].log >| temp_$[i+7].log 
sed 's/dst_w//g' temp_$[i+7].log >| temp_$[i+8].log
sed 's/dst_h//g' temp_$[i+8].log >| temp_$[i+9].log
sed 's/dst_line_stride//g' temp_$[i+9].log >| temp_$[i+10].log
sed 's/matirx//g' temp_$[i+10].log >| temp_$[i+11].log
sed 's/{//g' temp_$[i+11].log >| temp_$[i+12].log
sed 's/}//g' temp_$[i+12].log >| temp_$[i+13].log
sed 's/\[//g' temp_$[i+13].log >| temp_$[i+14].log
sed 's/\]//g' temp_$[i+14].log >| temp_$[i+15].log
sed 's/://g' temp_$[i+15].log >| test_out.txt

rm -rf temp_*.log

######            2.   classify recoder           ######
######

declare -a MD
declare -a SRC
declare -a DST

mode_1=0
mode_2=0
mode_3=0
mode_4=0
mode_5=0
mode_6=0
mode_7=0
mode_8=0
mode_9=0
mode_10=0

j=0

while read LINE
do
	mode=`echo $LINE | awk '{print $1}'`
	src_format=`echo $LINE | awk '{print $2}'`
	dst_format=`echo $LINE | awk '{print $6}'`
	MD[j]=$mode
	SRC[j]=$src_format
	DST[j]=$dst_format
	
	if [ "${MD[j]}" = "PERSP" ];then
		if [ "${SRC[j]}" = "ABRG" ];then
			if [ "${DST[j]}" = "ABRG" ];then
				mode_1=$[(++mode_1)]
			fi
		fi
		if [ "${SRC[j]}" = "AGRB" ];then
			if [ "${DST[j]}" = "AGRB" ];then
				mode_2=$[(++mode_2)]
			fi
		fi
		if [ "${SRC[j]}" = "AGBR" ];then
			if [ "${DST[j]}" = "AGBR" ];then
				mode_3=$[(++mode_3)]
			fi
		fi
	fi
	
	if [ "${MD[j]}" = "RSZ" ];then
		if [ "${SRC[j]}" = "ABRG" ];then
			if [ "${DST[j]}" = "ABRG" ];then
				mode_4=$[(++mode_4)]
			fi
		fi
		if [ "${SRC[j]}" = "AGRB" ];then
			if [ "${DST[j]}" = "AGRB" ];then
				mode_5=$[(++mode_5)]
			fi
		fi
		if [ "${SRC[j]}" = "AGBR" ];then
			if [ "${DST[j]}" = "AGBR" ];then
				mode_6=$[(++mode_6)]
			fi
		fi
	fi
	
	if [ "${MD[j]}" = "AFFINE" ];then
		if [ "${SRC[j]}" = "ABRG" ];then
			if [ "${DST[j]}" = "ABRG" ];then
				mode_7=$[(++mode_7)]
			fi
		fi
		if [ "${SRC[j]}" = "ARGB" ];then
			if [ "${DST[j]}" = "ARGB" ];then
				mode_8=$[(++mode_8)]
			fi
		fi
		if [ "${SRC[j]}" = "AGRB" ];then
			if [ "${DST[j]}" = "AGRB" ];then
				mode_9=$[(++mode_9)]
			fi
		fi
	fi
	
#	if [ "$j" -gt "1" ]; then
#		if [ "${MD[j]}" =  "${MD[j-1]}" ]; then
#		fi
#	fi
		let "j++"
done < test_out.txt
echo "PERSP  ABRG -> ABRG total number: $mode_1 "  > ./mode_result.txt
echo "AFFINE ABRG -> ABRG total number: $mode_2 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_3 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_4 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_5 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_6 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_7 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_8 "  >> ./mode_result.tx
echo "AFFINE ABRG -> ABRG total number: $mode_9 "  >> ./mode_result.tx


