# Search_Engine

import_spbu_umd.sh - a bash script for loading and unpacking resources of SPbU.

## Usage

    import_spbu_umd [option...]

`-s | --source` url address from which resources should be downloaded (default is https://spbu.ru/sveden/education` ) 

 `-d | --destination` directory where resources should be saved (default is ./downloads/)

`-p | --probe` if specified, 10 random resources will be downloaded

### Example

`import_spbu_umd -s 'https://spbu.ru/sveden/education' -d './folder_to_download_to' -p.`




