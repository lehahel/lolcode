flexer: scanner.l parser.y
	flex scanner.l
	bison -d parser.y -o parser.hh
	g++ lex.yy.cc parser.hh driver.hh lolobject.cpp location.hh -lfl --with-unixodbc=/usr

