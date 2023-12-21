# Desctop Search

import_spbu_umd.sh - a bash script for loading and unpacking resources of SPbU.

## Usage

    import_spbu_umd [option...]

`-s | --source` url address from which resources should be downloaded (default is https://spbu.ru/sveden/education` ) 

 `-d | --destination` directory where resources should be saved (default is ./downloads/)

`-p | --probe` if specified, 10 random resources will be downloaded

### Example

`import_spbu_umd -s 'https://spbu.ru/sveden/education' -d './folder_to_download_to' -p.`

### Recoll search

`recoll -c ./.recoll -t <query>` 

### Requirements

- unzip

- recoll - Desctop text search. [Manual]([Recoll user manual](https://www.lesbonscomptes.com/recoll/usermanual/usermanual.html#RCL.SEARCH.GUI.RESULTLIST.MENU.SNIPPETS)) 
