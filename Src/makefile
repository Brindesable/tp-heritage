# CONSTANTS
##################################################################

INCPATH="/usr/include/c++/4.7.2/"
LIBPATH=

TARGET=draw

CC=@g++
CPPFLAGS=-Wall -I$(INCPATH)
LD=@g++
LDFLAGS=-lstdio -lstdlib -liostream -lstring

CONFIG_HEA=Constants.h

HEA=Application.h Figure.h Shape.h Selection.h Circle.h Rectangle.h Polyline.h Line.h Point.h
THEA=TFigure.h TSelection.h TCircle.h TRectangle.h TPolyline.h TLine.h
SRC=$(HEA:.h=.cpp) $(THEA:.h=.cpp)
OBJ=$(SRC:.cpp=.o)

ECHO=@echo
RM=@rm
RMFLAGS=-f

TEST_OUTPUT=TEST.LOG

.PHONY:clean debug tests

#MAKE
##################################################################

$(TARGET) : Main.o $(OBJ)
	$(ECHO) "Linking <$@>"
	$(CC) $(CPPFLAGS) -o $@ Main.o $(OBJ)

#MAKE CLEAN
##################################################################

clean:	
	$(ECHO) "Cleaning project directory !"
	$(RM) $(RMFLAGS) $(OBJ) $(TARGET) $(TEST_OUTPUT) Main.o core
	$(ECHO) "done."

#MAKE NO_COMMENTS
##################################################################

no-comments:
	$(ECHO) "Making no comments version"
	@make CPPFLAGS=-DNO_COMMENTS
	$(ECHO) "done !"

#MAKE DEBUG
##################################################################

debug:
	$(ECHO) "Making debug version"
	@make CPPFLAGS=-DMAP
	$(ECHO) "done !"

#MAKE TESTS
##################################################################

tests:
	$(ECHO) "Making test version"
	@make CPPFLAGS=-DTEST
	$(ECHO) "Running tests..."
	@chmod 770 $(TARGET)
	@nohup ./$(TARGET) > $(TEST_OUTPUT) 2>&1 &
	$(ECHO) "done."

#FILES BUILDING RULES
##################################################################

Main.o : Main.cpp
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Application.o : Application.cpp Application.h Figure.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Figure.o : Figure.cpp Figure.h Circle.h Polyline.h Line.h Rectangle.h Selection.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Selection.o : Selection.cpp Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Shape.o : Shape.cpp Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Polyline.o : Polyline.cpp Polyline.h Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Circle.o : Circle.cpp Circle.h Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Line.o : Line.cpp Line.h Polyline.h Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Rectangle.o : Rectangle.cpp Rectangle.h Polyline.h Shape.h Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

Point.o : Point.cpp Point.h $(CONFIG_HEA)
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TFigure.o : UnitTests/TFigure.cpp UnitTests/TFigure.h Figure.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TSelection.o : UnitTests/TSelection.cpp UnitTests/TSelection.h Selection.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TCircle.o : UnitTests/TCircle.cpp UnitTests/TCircle.h Circle.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TPolyline.o : UnitTests/TPolyline.cpp UnitTests/TPolyline.h Polyline.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TRectangle.o : UnitTests/TRectangle.cpp UnitTests/TRectangle.h Rectangle.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<

TLine.o : UnitTests/TLine.cpp UnitTests/TLine.h Line.h
	$(ECHO) "Compiling <$<>"
	$(CC) $(CPPFLAGS) -c $<
