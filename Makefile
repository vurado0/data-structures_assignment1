.PHONY: clean All

All:
	@echo "==========Building project:[ Assignment1 - Debug ]=========="
	@cd "Assignment1" && "$(MAKE)" -f  "Assignment1.mk"
clean:
	@echo "==========Cleaning project:[ Assignment1 - Debug ]----------"
	@cd "Assignment1" && "$(MAKE)" -f  "Assignment1.mk" clean
