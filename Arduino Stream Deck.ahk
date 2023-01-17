#SingleInstance, force ; DEBUG nur ein Skript läuft auf einmal

; Startet ein Programm nach Wahl
^+1:: Run "C:\PROGRAMMPFAD\PROGRAMM.EXE"

; Discord Mikrofon ein & aus Schalter
ifWinActive, ahk_exe Discord.exe ; Prüft ob Discord aktiv ist
{
	^+2::
		WinGetActiveTitle , AktivesFenster ; Speichert das aktiv offene Fenster
		WinGet , DiscordState , MinMax , ahk_exe Discord.exe ; Prüft ob Discord auf dem Bildschirm sichtbar ist
		WinActivate , ahk_exe Discord.exe ; Setzt Discord in den Vordergrund
		Send ^+m ; Drückt die Tastenkombination Ctrl Shift M um das Mikrofon ein und auszuschalten
		IfEqual DiscordState , -1 , WinMinimize , ahk_exe Discord.exe ; Wenn Discord im Hintergrund war wird es wieder in den Hintergrund gesetzt
		WinActivate , %AktivesFenster% ; Setzt das Fenster welches am Anfang aktiv war wieder in den Vordergrund
		return

	^+3::
		WinGetActiveTitle , AktivesFenster ; Speichert das aktiv offene Fenster
		WinGet , DiscordState , MinMax , ahk_exe Discord.exe ; Prüft ob Discord auf dem Bildschirm sichtbar ist
		WinActivate , ahk_exe Discord.exe ; Setzt Discord in den Vordergrund
		Send ^+d ; Drückt die Tastenkombination Ctrl Shift M um den Ton ein oder auszuschalten
		IfEqual DiscordState , -1 , WinMinimize , ahk_exe Discord.exe ; Wenn Discord im Hintergrund war wird es wieder in den Hintergrund gesetzt
		WinActivate , %AktivesFenster% ; Setzt das Fenster welches am Anfang aktiv war wieder in den Vordergrund
		return
}

; Setzt die Lautstärke auf 30
^+4:: SoundSet , 30

; Easter Egg RickRoll
^+ü::
	Run "https://youtu.be/dQw4w9WgXcQ"
	Sleep , 5000 ; Wartet 5 Sekunden bis das Video geladen ist
	Send {Space} ; Drückt die Leertaste um das Video zu starten
	return
