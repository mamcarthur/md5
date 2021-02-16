# md5 sha256 sha512 sha224 sha384

In this project I recreated 5 different popular hash functions. Hash functions 
take in data and spit out a deterministic, fixed-length number, called a hash. 
Because it's nearly impossible to reverse-engineer the original message from 
these hashes, and slight differences in the message produce vastly different 
hashes, it has many uses in authentication and verification of information 
integrity. sha256 is used in the Bitcoin protocol. The real challenge of this 
project was debugging the algorithm, since it was impossible to tell what went 
wrong from reading the output. The painstaking attention to detail required 
to locate the errors taught me the value of clear, readable code that gets the
job done right the first time.

# Usage

Build with `make` or `make re`.

`./ft_ssl [HASH_FUNCTION] -[MODE] [INPUT]`

Hash functions:
```bash
md5
sha224
sha256
sha384
sha512
```

Modes:  
`-p` write message on standard input  
`-q` quiet mode--shows only the hash  
`-r` reverse format--prints the hash first, then reprints the message after  
`-s` take string instead of a file  

# Examples

```bash
$ ./ft_ssl md5 -s "haha"
MD5("haha")= 4e4d6c332b6fe62a63afe56171fd3725
```
```bash
$ echo "hehe" | ./ft_ssl md5
e4439267203fb5277d347e6cd6e440b5
```
```bash
$ ./ft_ssl sha224 example.txt
SHA224(example.txt)= adbc0e78670e40dbe3443227eedafacde89883a3229ad17b9079e762
```
```bash
$ ./ft_ssl sha512 -q example.txt
aced30a57ad9d56f272dce155e370ef7b5d2ef99c7aae6e5f9d0e1e62e4966163955b35a801cfe09f0d320a1b94a22c102bb174a66d2a1d974dba0072ffdc981
```
```bash
$ ./ft_ssl sha384 -r -s "example"
feeebf884f6dabe6eca8d68e373d6be488cdaa5eb764e895290336ffe9ff969686f2a9d362e9a8bbddf6e7b2e1455f2d "example"
```
```bash
./ft_ssl sha256 -p
my message
on stdin
my message
on stdin
e955158c7fe7ed9f5f77c86c200e902f7a88a5fc7f88235f370cb6e6127cf85d
```
