#### Ex1
Softlink and Hardlink
[__Useful Link__](http://www.geekride.com/hard-link-vs-soft-link/)

Command `tr`
[__Useful Link__](http://www.thegeekstuff.com/2012/12/linux-tr-command/)

Command `cut`
[__Useful Link__](http://www.thegeekstuff.com/2013/06/cut-command-examples/)

Command `grep`
[__Useful Link__](http://www.thegeekstuff.com/2009/03/15-practical-unix-grep-command-examples/)


`cut -d: -f5 /stage/classes/archive/2016/winter/51081-1/labs/introlab/ypcat.out | grep ^John\\s | wc -l`

`lpq -a`

`ps -U root | cut -c-5 | sed '1d' | tr '\n' ',' | tr -d ' '`

`finger | cut -c-33 | sed '1d' | uniq | sort | nl`
