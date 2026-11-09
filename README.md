# echzeitsyteme_process


Ziel dieses Projekts ist es, die Grundlagen der Prozessverwaltung und der Umgebungsvariablen unter Linux in der Programmiersprache C praktisch umzusetzen. Alle Programme lassen sich über das beigefügte `Makefile` mit strengen Compilerflags (`-W -Wall -Wextra -Werror`) ohne Warnungen kompilieren.

## Übersicht der Aufgaben

* **Aufgabe 1 (`auf1.c`) – Verwaister Kindprozess:**
  Ein Elternprozess erzeugt einen Kindprozess mit `fork()` und beendet sich direkt danach. Das Programm zeigt mithilfe von `getppid()`, dass der verwaiste Kindprozess vom Systemprozess `init` / `systemd` (PID 1) übernommen wird. Zusätzlich gibt ein Exithandler (`atexit`) beim Beenden `"Goodbye"` zusammen mit dem Benutzernamen (`getuid`, `getpwuid`) aus.

* **Aufgabe 2 (`auf2.c`) – Zombie-Prozesse:**
  Das Programm erzeugt eine über die Kommandozeile festgelegte Anzahl $k$ an Zombie-Prozessen, indem der Elternprozess die beendeten Kindprozesse bewusst nicht mit `wait()` abholt. Mit dem Parameter `k = -1` werden so viele Zombies erzeugt, bis das Prozesslimit des Systems erreicht ist.

* **Aufgabe 3 (`auf3.c`) – Prozess-Environment:**
  Ein interaktives Konsolenprogramm zur Verwaltung von Environment-Variablen. Über ein Menü lassen sich alle Variablen anzeigen, gezielt abfragen sowie neue Einträge hinzufügen, ändern oder löschen (`getenv`, `setenv`, `unsetenv`, `readline`).

## Kompilierung und Ausführung

Um alle Programme gleichzeitig zu kompilieren, führen Sie im Hauptverzeichnis folgenden Befehl aus:

```bash
make
```

### Beispielaufrufe

```bash
# Aufgabe 1 starten
./auf1

# Aufgabe 2 mit 5 Zombie-Prozessen im Hintergrund starten
./zombie 5 &

# Zombie-Prozesse im System überprüfen
ps axo stat,pid,comm | grep Z

# Aufgabe 3 (Interaktives Menü) starten
./auf3
```

