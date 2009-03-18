PROJECT (fscontent)

#CHEQUEO DE LA LIBRERIA ext2fs
FIND_PATH(E2FS_INCLUDE_DIR ext2fs.h
/usr/local/include
/usr/include
/usr/local/include/ext2fs
/usr/include/ext2fs
)

FIND_LIBRARY(E2FS_LIBRARY ext2fs
/usr/lib
/usr/local/lib
)


IF (E2FS_LIBRARY)
  IF (E2FS_INCLUDE_DIR)
    SET(E2FS_LIBRARIES ${E2FS_LIBRARY})
    SET(E2FS_FOUND "YES")
  ENDIF (E2FS_INCLUDE_DIR)
ENDIF (E2FS_LIBRARY)

# Deprecated declarations.
SET (NATIVE_E2FS_INCLUDE_PATH ${E2FS_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_E2FS_LIB_PATH ${E2FS_LIBRARY} PATH)

MARK_AS_ADVANCED(
  E2FS_LIBRARY
  E2FS_INCLUDE_DIR
  )
#nousa
LINK_LIBRARIES(${E2FS_LIBRARY})

#CHEQUEO DE LA LIBRERIA mysql
FIND_PATH(MYSQL_INCLUDE_DIR mysql.h
/usr/local/include
/usr/include
/usr/local/include/mysql
/usr/include/mysql
)

FIND_LIBRARY(MYSQL_LIBRARY mysqlclient
/usr/lib
/usr/local/lib
)


IF (MYSQL_LIBRARY)
  IF (MYSQL_INCLUDE_DIR)
    SET(MYSQL_LIBRARIES ${MYSQL_LIBRARY})
    SET(MYSQL_FOUND "YES")
  ENDIF (MYSQL_INCLUDE_DIR)
ENDIF (MYSQL_LIBRARY)

# Deprecated declarations.
SET (NATIVE_MYSQL_INCLUDE_PATH ${MYSQL_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_MYSQL_LIB_PATH ${MYSQL_LIBRARY} PATH)

MARK_AS_ADVANCED(
  MYSQL_LIBRARY
  MYSQL_INCLUDE_DIR
  )
#enlazamos
LINK_LIBRARIES(${MYSQL_LIBRARY})

#agregamos los binarios
ADD_EXECUTABLE (fscontent main.c fscontent.c mysqlmanager.c session.c)

#FIND_LIBRARY(EXT2FSLIB NAMES libext2fs ext2fs
# PATHS /usr/lib /usr/local/lib)




#IF (EXT2FSLIB)
# TARGET_ADD_LIBRARY (fscontent EXT2FSLIB)
#ENDIF (EXT2FSLIB)


#original Makefile.am contents follow:

#templateName = fscontent

#### no need to change below:
#template_DATA = $(templateName).kdevtemplate
#templatedir = ${appwizarddatadir}/templates
#
#appwizarddatadir = ${kde_datadir}/kdevappwizard
#$(templateName).tar.gz:
	#$(TAR) -cf $(templateName).tar -C $(srcdir) ${dataFiles}
#	$(GZIP) -9 $(templateName).tar

#archivedir = ${appwizarddatadir}

#archive_DATA = $(templateName).tar.gz ${templateName}.png
#

#CLEANFILES = *.tar.gz
