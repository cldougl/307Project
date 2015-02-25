# A simple Tcl/Tk example script

# Set initial control values
set speedfast 0.0
set speedmed 0.0
set speedslow 0.0 
set voice1 0.0
set voice2 0.0
set voice3 0.0
set voice4 0.0
set voice5 0.0
set voice6 0.0
set voice7 0.0
set voice8 0.0
set Stop 0.0

set preset 0

# Configure main window
wm title . "Chelsea's 307 Project"
wm iconname . "simple"
. config -bg pink

# Configure a "note-on" button
frame .button1 -bg pink
frame .button2 -bg pink
frame .button3 -bg pink

button .button1.1 -text "Voice 1" -bg pink -command { controlChange 1 }
button .button1.2 -text "Voice 2" -bg pink -command { controlChange 2 }
button .button1.3 -text "Voice 3" -bg pink -command { controlChange 3 }
button .button1.4 -text "Voice 4" -bg pink -command { controlChange 4 }
button .button2.5 -text "Voice 5" -bg pink -command { controlChange 5 }
button .button2.6 -text "Voice 6" -bg pink -command { controlChange 6 }
button .button2.7 -text "Voice 7" -bg pink -command { controlChange 7 }
button .button2.8 -text "Voice 8" -bg pink -command { controlChange 8 }
button .button3.9 -text "Speed Slow" -bg pink -command { controlChange 9 }
button .button3.10 -text "Speed Medium" -bg pink -command { controlChange 10 }
button .button3.11 -text "Speed Fast" -bg pink -command { controlChange 11 }


#pack .buttons.1 -side left -padx 5
pack .button1.1 -side left -padx 5
pack .button1.2 -side left -padx 5
pack .button1.3 -side left -padx 5
pack .button1.4 -side left -padx 5
pack .button1

pack .button2.5 -side left -padx 5
pack .button2.6 -side left -padx 5
pack .button2.7 -side left -padx 5
pack .button2.8 -side left -padx 5
pack .button2

pack .button3.9 -side bottom -padx 5
pack .button3.10 -side bottom -padx 5
pack .button3.11 -side bottom -padx 5
pack .button3

# Bind an X windows "close" event with the Exit routine
bind . <Destroy> +myExit

proc myExit {} {
    puts [format "ExitProgram"]
    flush stdout
    close stdout
    exit
}

proc noteOn {pitchVal pressVal} {
    puts [format "NoteOn           0.0 1 %f %f" $pitchVal $pressVal]
    flush stdout
}

proc controlChange {value} {
    global voice1 voice2 voice3 voice4 voice5 voice6 voice7 voice8 stop
    set value1 $value
    set value2 0
    if { $value == 1 } { # voice 1
        if { $voice1 == 0 } {
            set voice1 1
        } else {
            set voice1 0
        }
        set value2 $voice1
    }
    if { $value == 2 } { # voice 2
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    } 
    if { $value == 3 } { # voice 3
        if { $voice1 == 0 } {
            set voice1 1
        } else {
            set voice1 0
        }
        set value2 $voice1
    }
    if { $value == 4 } { # voice 4
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    } 
    if { $value == 5 } { # voice 5
        if { $voice1 == 0 } {
            set voice1 1
        } else {
            set voice1 0
        }
        set value2 $voice1
    }
    if { $value == 6 } { # voice 6
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    } 
    if { $value == 7 } { # voice 7
        if { $voice1 == 0 } {
            set voice1 1
        } else {
            set voice1 0
        }
        set value2 $voice1
    }
    if { $value == 8 } { # voice 8
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    }
    if { $value == 9 } { # voice 9
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    }
    if { $value == 10 } { # voice 10
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    }
    if { $value == 11 } { # voice 11
        if { $voice2 == 0 } {
            set voice2 1
        } else {
            set voice2 0
        }
        set value2 $voice2
    }


    puts [format "ControlChange      0.0 1 %.3f %.3f" $value1 $value2]
    flush stdout
}

bind . <Configure> {+ center_the_toplevel %W }
proc center_the_toplevel { w } {

    # Callback on the <Configure> event for a toplevel
    # that should be centered on the screen

    # Make sure that we aren't configuring a child window
    if { [string equal $w [winfo toplevel $w]] } {

        # Calculate the desired geometry
        set width [winfo reqwidth $w]
        set height [winfo reqheight $w]
        set x [expr { ( [winfo vrootwidth  $w] - $width  ) / 2 }]
        set y [expr { ( [winfo vrootheight $w] - $height ) / 2 }]
        #set y 0

        # Hand the geometry off to the window manager
        wm geometry $w ${width}x${height}+${x}+${y}

        # Unbind <Configure> so that this procedure is
        # not called again when the window manager finishes
        # centering the window.  Also, revert geometry management
        # to internal default for subsequent size changes.
        bind $w <Configure> {}
        wm geometry $w ""
    }

    return
}
