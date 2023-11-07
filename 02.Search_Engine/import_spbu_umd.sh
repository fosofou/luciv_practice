#!/bin/bash

dl_spbu_s_e () {
    curl "$source" -s --compressed -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:109.0) Gecko/20100101 Firefox/118.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8' -H 'Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3' -H 'Accept-Encoding: gzip, deflate, br' -H 'DNT: 1' -H 'Connection: keep-alive'
}

dl_spbu_oop () {
    dl_spbu_s_e | grep -o -P "'https://nc\.spbu\.ru/.+?'" | sed "s/'//g" | sort | uniq | ($probe && (sort -R | head -n 10) || cat)
     
}

function download {
    if ! wget "$1/download" -O "$destination$2.zip"; then
        >&2 echo "Cannot download $1" 
        return 15
    fi
    
}

#default input params
source=https://spbu.ru/sveden/education
destination=./downloads/
probe=false


function check_arg()
{
    if [[ "$2" == "-*" ]]; then
        echo "Option $1 requires an argument" >&2
	return 15
    fi
}

getopt_args=''

if ! getopt_args=$(getopt -o s::d::p --long source:,destination:,probe -- "$@"); then
    exit 1;
fi

eval set -- "$getopt_args"

while [ true ]; 
do
    case $1 in
    -s | --source)
        check_arg "$1" "$2"
	source=$1
	shift 2
        ;;
    -d | destination)
        check_arg "$1" "$2"
	destination=$2
	if ! [ ${destination: -1} = "/" ]; then
	     destination="${destination}/"
	fi
	shift 2
	;;
    -p|--probe)
        probe=true
        shift
        ;;
    --) 
	shift
        break
        ;;
    esac
done

# check if the directory already exists
if ! [ -e "$destination" ]; then
    mkdir ${destination}
fi

file_num=0

for url in $(dl_spbu_oop); do
    download "${url}" "${file_num}"
    unzip "$destination${file_num}.zip" -d "$destination${file_num}"
    rm "$destination${file_num}.zip"
    ((++file_num))
done


