@echo off

if not exist venus_theme_generator.pl goto ERR

perl venus_theme_generator.pl

IF ERRORLEVEL 0 (
    type ThemeXML\Log\venus_theme_generator.log
    goto DONE
) ELSE (
    type ThemeXML\Log\venus_theme_generator.log
    goto ERR
)

goto DONE

:ERR
echo venus_theme_generator.bat got error.
exit /B 2

:DONE
exit /B 1
