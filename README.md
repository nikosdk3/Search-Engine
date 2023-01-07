# Search Engine
Txt-file based search engine which uses map and set abstractions to make indexing for a user's query faster.

## Usage

### Building
- Clone this repository
- Run `make build`

### Running
- Run `make run`

### Data Files
The format for the data files are the following:

- The lines of the file are grouped into pairs with the following structure:
  - The first line of a pair is the page URL.
  - The second line of a pair is the text of the page in a single string
- For example, the first two lines in the file form the first pair, the third and fourth are the second pair, the fifth and sixth are the third pair, and so on...

To view a compact example data file, open `tiny.txt`

### Changing data files
To change which data file is being indexed, edit the parameter for the `searchEngine` function call in main.cpp 

## Sample execution

```
Stand by while building index...
Indexed 86 pages containing 1498 unique terms

Enter query sentence (press enter to quit): vector
Found 8 matching pages
https://www.cplusplus.com/reference/array/array/
https://www.cplusplus.com/reference/bitset/bitset/
https://www.cplusplus.com/reference/forward_list/forward_list/
https://www.cplusplus.com/reference/list/list/
https://www.cplusplus.com/reference/queue/priority_queue/
https://www.cplusplus.com/reference/stack/stack/
https://www.cplusplus.com/reference/vector/vector-bool/
https://www.cplusplus.com/reference/vector/vector/

Enter query sentence (press enter to quit): vector +container
Found 7 matching pages
https://www.cplusplus.com/reference/array/array/
https://www.cplusplus.com/reference/forward_list/forward_list/
https://www.cplusplus.com/reference/list/list/
https://www.cplusplus.com/reference/queue/priority_queue/
https://www.cplusplus.com/reference/stack/stack/
https://www.cplusplus.com/reference/vector/vector-bool/
https://www.cplusplus.com/reference/vector/vector/

Enter query sentence (press enter to quit): vector +container -pointer
Found 6 matching pages
https://www.cplusplus.com/reference/array/array/
https://www.cplusplus.com/reference/forward_list/forward_list/
https://www.cplusplus.com/reference/list/list/
https://www.cplusplus.com/reference/queue/priority_queue/
https://www.cplusplus.com/reference/stack/stack/
https://www.cplusplus.com/reference/vector/vector/

Enter query sentence (press enter to quit):
Thank you for searching!
```
