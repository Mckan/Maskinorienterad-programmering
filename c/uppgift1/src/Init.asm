	segment		init			Länka till init
	export		_exit			Exportera funktionen
	import		_main			Importera funktionen
	function	__start,__start_end	debug kod
	
*
__start	NOP					Start pos för debug
	LDS		#$2FFF			Sätt stacken
	JSR		_main			Hoppa till main
_exit:	NOP					Start på loop
	BRA		_exit
__start_end NOP					Slut pos för debug