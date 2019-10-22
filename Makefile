.PHONY: clean All

All:
	@echo "----------Building project:[ UOCFlixMain - Release ]----------"
	@cd "UOCFlixMain" && "$(MAKE)" -f  "UOCFlixMain.mk"
clean:
	@echo "----------Cleaning project:[ UOCFlixMain - Release ]----------"
	@cd "UOCFlixMain" && "$(MAKE)" -f  "UOCFlixMain.mk" clean
