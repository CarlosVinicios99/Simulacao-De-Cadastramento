	Neste projeto existe um menu com 5 opções:

1) Realizar Cadastro:
	O usuário informa seu nome, idade e cidade e seu registro é realizado.

2) Remover Cadastro:
	o nome do usuário deve ser informado e em seguida o registro referente ao nome do usuário é removido

3) Consultar Cadastro:
	o nome do usuário é informado e em seguida os dados do registros referente ao nome do usuário são mostrados na tela

4) Listar Cadastros:
	Todos os dados de todos os registros são mostrados na tela.

5) Sair:
	Ocorre o salvamento dos dados e a liberação de memoria, em seguida o programa
é encerrado.

	No inicio da execução do programa possíveis registros existentes são carregados em memoria e podem ser manipulados, ao fim do programa os registros em memoria são salvos novamente.
	No desenvolvimento deste projeto foram utilizados arquivos binários para o salvamento de dados e um TAD lista para auxiliar nas  demais operações realizadas no programa.
	
	Para compilar deve ser utilizado um compilador de C, no caso utilizei tanto o GCC quanto o G++.
	
	COMPILANDO:
		GCC cadastramento.c lista.c -o cadastramento.exe
		
	EXECUTANDO:
		./cadastramento.exe

