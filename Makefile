default:
	gcc ls1.c -o ls1
	gcc cat1.c -o cat1
	gcc rm1.c -o rm1
	gcc mkdir1.c -o mkdir1
	gcc date1.c -o date1
	gcc shell.c 
	./a.out



preprocessStage:
	gcc -E date1.c -o date1.i
	gcc -E ls1.c -o ls1.i
	gcc -E mkdir1.c -o mkdir1.i
	gcc -E cat1.c -o cat1.i
	gcc -E shell.c -o shell.i



compileStage:
	gcc -S date1.c
	gcc -S ls1.c
	gcc -S mkdir1.c
	gcc -S cat1.c
	gcc -S shell.c 
	
	
	

assemblerStage: 
	gcc -c date1.c
	gcc -c mkdir1.c
	gcc -c ls1.c
	gcc -c cat1.c
	gcc -c shell.c
	


linker:
	gcc cat1.c -o cat1
	gcc rm1.c -o rm1
	gcc date1.c -o date1
	gcc ls1.c -o ls1
	gcc mkdir1.c -o mkdir1
	gcc shell.c