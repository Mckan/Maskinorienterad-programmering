	segment		init			L�nka till init
	export		_exit			Exportera funktionen
	import		_main			Importera funktionen
	function	__start,__start_end	debug kod
	
*
__start	NOP					Start pos f�r debug
	LDS		#$2FFF			S�tt stacken
	JSR		_main			Hoppa till main
_exit:	NOP					Start p� loop
	BRA		_exit
__start_end NOP					Slut pos f�r debug