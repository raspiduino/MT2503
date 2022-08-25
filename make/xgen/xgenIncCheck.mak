Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

-include make\folderlist.bld

CheckPCIBT = \
$(strip \
  $(foreach \
    inc,\
    $(filter-out $(call Upper,custom\\%),$(call Upper,$(1))),\
    $(if \
      $(filter $(patsubst %\,%,$(dir $(inc))),$(call Upper,$(FOLDERLIST))),\
      ,\
      $(inc)\
    )\
  )\
)

.PHONY: $(DEP_FILE)

include .\$(DEP_FILE)
$(DEP_FILE):
	@if not $(words $(call CheckPCIBT,$^))==0 \
	( \
		(perl -e "print 'Error: The following file in $(DEP_FILE) can\'t be found in subsidiary perforce: '.'$(call CheckPCIBT,$^)'.\"\n\";">> $(LOG)) & \
		(perl -e "print \"It will let subsidiary get build errors. Please do not use these source files or not include these header files, or move these files to permission-opened folders.\".\"\n\";">> $(LOG)) & \
		(perl -e "print 'Please check $(LOG) for xgen include path permission check in build time [PCIBT]'.\"\n\";") & \
		(exit 1)\
	) \
	else \
	( \
		echo [PCIBT] pass! \
	)
