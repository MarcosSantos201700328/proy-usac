<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>bloque_db.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>bloque__db_8cpp</filename>
    <includes id="bloque__db_8h" name="bloque_db.h" local="yes" imported="no">bloque_db.h</includes>
  </compound>
  <compound kind="file">
    <name>bloque_db.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>bloque__db_8h</filename>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
    <class kind="struct">bloque_db</class>
  </compound>
  <compound kind="file">
    <name>database.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>database_8h</filename>
    <includes id="indicewrapper_8h" name="indicewrapper.h" local="yes" imported="no">indicewrapper.h</includes>
    <includes id="ericleresultsetwidget_8h" name="ericleresultsetwidget.h" local="yes" imported="no">ericleresultsetwidget.h</includes>
    <includes id="tipos_8h" name="tipos.h" local="yes" imported="no">tipos.h</includes>
    <includes id="dataoperations_8h" name="dataoperations.h" local="yes" imported="no">dataoperations.h</includes>
    <includes id="metadata_8h" name="metadata.h" local="yes" imported="no">metadata.h</includes>
    <includes id="bloque__db_8h" name="bloque_db.h" local="yes" imported="no">bloque_db.h</includes>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
    <includes id="tablespace_8h" name="tablespace.h" local="yes" imported="no">tablespace.h</includes>
    <includes id="result_8h" name="result.h" local="yes" imported="no">result.h</includes>
    <includes id="registro_8h" name="registro.h" local="yes" imported="no">registro.h</includes>
    <includes id="r__usuario_8h" name="r_usuario.h" local="yes" imported="no">r_usuario.h</includes>
    <class kind="class">database</class>
    <member kind="typedef">
      <type>QMap&lt; unsigned int, IndiceWrapper &gt;</type>
      <name>IndexMap</name>
      <anchorfile>database_8h.html</anchorfile>
      <anchor>5c33788d938bfe2c839cdd6aec6f2d21</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>QMap&lt; QString, r_usuario &gt;</type>
      <name>UserMap</name>
      <anchorfile>database_8h.html</anchorfile>
      <anchor>70f9186f25c40dab255a6098d01af461</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>dataoperations.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>dataoperations_8h</filename>
    <includes id="tipos_8h" name="tipos.h" local="yes" imported="no">tipos.h</includes>
    <includes id="registro_8h" name="registro.h" local="yes" imported="no">registro.h</includes>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
    <includes id="metadata_8h" name="metadata.h" local="yes" imported="no">metadata.h</includes>
    <includes id="tablespace_8h" name="tablespace.h" local="yes" imported="no">tablespace.h</includes>
    <includes id="r__autor_8h" name="r_autor.h" local="yes" imported="no">r_autor.h</includes>
    <includes id="r__contenido_8h" name="r_contenido.h" local="yes" imported="no">r_contenido.h</includes>
    <includes id="r__libro_8h" name="r_libro.h" local="yes" imported="no">r_libro.h</includes>
    <includes id="r__prestamo_8h" name="r_prestamo.h" local="yes" imported="no">r_prestamo.h</includes>
    <includes id="r__tipousuario_8h" name="r_tipousuario.h" local="yes" imported="no">r_tipousuario.h</includes>
    <includes id="r__usuario_8h" name="r_usuario.h" local="yes" imported="no">r_usuario.h</includes>
    <includes id="r__titulo_8h" name="r_titulo.h" local="yes" imported="no">r_titulo.h</includes>
    <member kind="function">
      <type>void</type>
      <name>setMetadata</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>c6fec4c6efe6b7627d93d5956de22d23</anchor>
      <arglist>(metadata *d)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTablespace</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>7cd0736210ad771944d915fa47b7eb5d</anchor>
      <arglist>(tablespace *t)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarTupla</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>41f5aa7b8b7a04af0d2be06898a023f2</anchor>
      <arglist>(linkedlist *datos, int tabla)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarAutor</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>aeb8dd0bd6e13c4edffea03f70490aeb</anchor>
      <arglist>(r_autor *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarLibro</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>86c832f24d9ca8885c869036f8088049</anchor>
      <arglist>(r_libro *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarContenido</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>0a40a4a510271e4e86b3a33d9c0a51fe</anchor>
      <arglist>(r_contenido *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarPrestamo</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>b456843fb394c3a03829adf6f11e2dc3</anchor>
      <arglist>(r_prestamo *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarTipoUsuario</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>087e1d30b7bcb92cfad12a1cf61fe615</anchor>
      <arglist>(r_tipousuario *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarTitulo</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>3c2499bb537fa2e9940c301a19057bc6</anchor>
      <arglist>(r_titulo *dato)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insertarUsuario</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>6602e4c499066134c1150d006cf4788d</anchor>
      <arglist>(r_usuario *dato)</arglist>
    </member>
    <member kind="function">
      <type>registro *</type>
      <name>leerRegistro</name>
      <anchorfile>dataoperations_8h.html</anchorfile>
      <anchor>ed33dc595fc1bfe4f11c225ac6ea5c9c</anchor>
      <arglist>(int numregistro, int tipo)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ericle.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>ericle_8cpp</filename>
    <includes id="ericlemainwindow_8h" name="ericlemainwindow.h" local="yes" imported="no">ericlemainwindow.h</includes>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>ericle_8cpp.html</anchorfile>
      <anchor>0ddf1224851353fc92bfbff6f499fa97</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ericleconfigdbdialog.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>ericleconfigdbdialog_8cpp</filename>
  </compound>
  <compound kind="file">
    <name>ericledeletelibrodialog.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>ericledeletelibrodialog_8h</filename>
    <class kind="class">EricleDeleteLibroDialog</class>
  </compound>
  <compound kind="file">
    <name>ericlemainwindow.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>ericlemainwindow_8h</filename>
    <includes id="database_8h" name="database.h" local="yes" imported="no">database.h</includes>
    <includes id="ericleresultsetwidget_8h" name="ericleresultsetwidget.h" local="yes" imported="no">ericleresultsetwidget.h</includes>
    <class kind="class">EricleMainWindow</class>
  </compound>
  <compound kind="file">
    <name>ericleresultsetwidget.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>ericleresultsetwidget_8h</filename>
    <class kind="class">EricleResultWidget</class>
  </compound>
  <compound kind="file">
    <name>indice.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indice_8cpp</filename>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
  </compound>
  <compound kind="file">
    <name>indice.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indice_8h</filename>
    <includes id="tipos_8h" name="tipos.h" local="yes" imported="no">tipos.h</includes>
    <class kind="struct">indice</class>
  </compound>
  <compound kind="file">
    <name>indice_directo.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indice__directo_8h</filename>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
    <class kind="class">indice_directo</class>
  </compound>
  <compound kind="file">
    <name>indice_indirecto.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indice__indirecto_8h</filename>
    <includes id="indice_8h" name="indice.h" local="no" imported="no">indice.h</includes>
    <class kind="class">indice_indirecto</class>
  </compound>
  <compound kind="file">
    <name>indicewrapper.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indicewrapper_8cpp</filename>
    <includes id="indicewrapper_8h" name="indicewrapper.h" local="yes" imported="no">indicewrapper.h</includes>
  </compound>
  <compound kind="file">
    <name>indicewrapper.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>indicewrapper_8h</filename>
    <includes id="indice_8h" name="indice.h" local="yes" imported="no">indice.h</includes>
    <class kind="class">IndiceWrapper</class>
  </compound>
  <compound kind="file">
    <name>logger.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>logger_8h</filename>
    <includes id="tipos_8h" name="tipos.h" local="yes" imported="no">tipos.h</includes>
    <includes id="registro_8h" name="registro.h" local="yes" imported="no">registro.h</includes>
    <member kind="function">
      <type>void</type>
      <name>iniciarLogFile</name>
      <anchorfile>logger_8h.html</anchorfile>
      <anchor>a028bfdfb6d5938207e00b50594a9887</anchor>
      <arglist>(const char *path)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mensajeLog</name>
      <anchorfile>logger_8h.html</anchorfile>
      <anchor>06f03d115a514058d0684d440cf6d44d</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalizarLogFile</name>
      <anchorfile>logger_8h.html</anchorfile>
      <anchor>ad47eeafe6a2c3591e57232b88bd93aa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>agregarMsgLog</name>
      <anchorfile>logger_8h.html</anchorfile>
      <anchor>b1a5326c093ed5c6960675114c3fdb1b</anchor>
      <arglist>(int, int, struct registro *)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>agregarErrorLog</name>
      <anchorfile>logger_8h.html</anchorfile>
      <anchor>3d34426bc9f521e783ae61ff1f2601ae</anchor>
      <arglist>(int, struct registro *)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>metadata.c</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>metadata_8c</filename>
    <includes id="metadata_8h" name="metadata.h" local="yes" imported="no">metadata.h</includes>
  </compound>
  <compound kind="file">
    <name>metadata.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>metadata_8h</filename>
    <class kind="struct">metadata</class>
  </compound>
  <compound kind="file">
    <name>modifylibro.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>modifylibro_8cpp</filename>
    <includes id="modifylibro_8h" name="modifylibro.h" local="yes" imported="no">modifylibro.h</includes>
  </compound>
  <compound kind="file">
    <name>modifylibro.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>modifylibro_8h</filename>
    <class kind="class">modifyLibro</class>
  </compound>
  <compound kind="file">
    <name>r_autor.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__autor_8h</filename>
    <class kind="struct">r_autor</class>
  </compound>
  <compound kind="file">
    <name>r_contenido.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__contenido_8h</filename>
    <class kind="struct">r_contenido</class>
  </compound>
  <compound kind="file">
    <name>r_libro.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__libro_8h</filename>
    <class kind="struct">r_libro</class>
  </compound>
  <compound kind="file">
    <name>r_prestamo.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__prestamo_8h</filename>
    <class kind="struct">r_prestamo</class>
  </compound>
  <compound kind="file">
    <name>r_tipousuario.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__tipousuario_8h</filename>
    <class kind="struct">r_tipousuario</class>
  </compound>
  <compound kind="file">
    <name>r_titulo.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__titulo_8h</filename>
    <class kind="struct">r_titulo</class>
  </compound>
  <compound kind="file">
    <name>r_usuario.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>r__usuario_8h</filename>
    <class kind="struct">r_usuario</class>
  </compound>
  <compound kind="file">
    <name>registro.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>registro_8h</filename>
    <includes id="r__autor_8h" name="r_autor.h" local="yes" imported="no">r_autor.h</includes>
    <includes id="r__contenido_8h" name="r_contenido.h" local="yes" imported="no">r_contenido.h</includes>
    <includes id="r__libro_8h" name="r_libro.h" local="yes" imported="no">r_libro.h</includes>
    <includes id="r__prestamo_8h" name="r_prestamo.h" local="yes" imported="no">r_prestamo.h</includes>
    <includes id="r__tipousuario_8h" name="r_tipousuario.h" local="yes" imported="no">r_tipousuario.h</includes>
    <includes id="r__titulo_8h" name="r_titulo.h" local="yes" imported="no">r_titulo.h</includes>
    <includes id="r__usuario_8h" name="r_usuario.h" local="yes" imported="no">r_usuario.h</includes>
    <class kind="struct">registro</class>
    <member kind="function">
      <type>registro *</type>
      <name>crearRegistro</name>
      <anchorfile>registro_8h.html</anchorfile>
      <anchor>f1afc32298d87ec563e63d91818885dc</anchor>
      <arglist>(void *datos, int tabla)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>result.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>result_8h</filename>
    <includes id="tupla_8h" name="tupla.h" local="yes" imported="no">tupla.h</includes>
    <class kind="class">result</class>
  </compound>
  <compound kind="file">
    <name>search_node.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>search__node_8h</filename>
    <class kind="struct">search_node</class>
  </compound>
  <compound kind="file">
    <name>tablespace.cpp</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>tablespace_8cpp</filename>
    <includes id="tablespace_8h" name="tablespace.h" local="yes" imported="no">tablespace.h</includes>
  </compound>
  <compound kind="file">
    <name>tablespace.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>tablespace_8h</filename>
    <class kind="struct">tablespace</class>
  </compound>
  <compound kind="file">
    <name>tipos.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>tipos_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>T_AUTOR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>b65089094898474874ae3fb4d8a52556</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_CONTENIDO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>733088247c52f5e58aa479ef8c9d770e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_LIBRO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>2a32305254cd1ba02ac9f4674227eab1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_PRESTAMO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>702829a28bb340a6479c4bbfd2bd76c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_TIPOUSUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>41b578e5a8ef8a0f3cc688c179b33db4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_TITULO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>59839404c482e96ea8388c5e87851bc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_USUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>32c28e66d3f68d72cec82408b714a15e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_IMAGEN</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>6ee6d94243cc00133c65425b90008f44</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_RESULT</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>c0c00e08512010092748f661c087f20b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_INDICE</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>25fcf3fb4f01feab94f8ae023e622c01</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_METADATA</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>0e2bc2507d8462cf883d93a660f16e4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_TABLESPACE</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>6c4e31920865d45e8e1f219fdd715fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_INDICE_DIR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>8c982f8b6e9c2d4cd1d30d88a7814e5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>T_INDICE_INDIR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>f6fd270ac3651dbbade1c66616b209fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MSGS_INSERCION</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>79a1f2ec38597221139a4f37097038d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MSGE_NOTENOUGHROOM</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>b75d681d3ec450b2d1f351860e241488</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MSGE_DUPLICADO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>6c452fc9fc01097853cd8704080e5f3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DIR_HOME</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>0af33f50a0667a85ef8682fa53c18f1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_DIRIDX</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>fb2f6f32d5e62577de06ec0ebb884886</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_INDIRIDX</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>bd12e6f2a7f74e4d5b11aabea24cf311</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBAUTOR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>b08ce42d18993271bdeebfa603f5f020</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBCONTENIDO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>7d0006fe6d3c36cc277fdc594724ade5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBLIBRO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>03e38434c321e1180d3df0e4597ac4c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBPRESTAMO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>066936daaa1d488c03e6caa9db8b142e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBTIPOUSUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>1c364bb28e44c33a305e2f5649dfb01e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBTITULO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>657c4cade4c040c2ca7634bafd77ce2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBUSUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>1926252a5d98ed7f31618aafe0a4e945</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_TBIMAGEN</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>4ac0c45bc9c37208b574ac4d973391d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_CONFIG</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>ba9fe34e3a7552565511d593cb0967f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_HEADER</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>bd2f3117eeb844e229c21c41966cd830</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FILE_DATA</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>56c171ce5fb653a8b2a10fa534cd870b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ERR_NULLPTR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>ff64af3643a0101598c3e97381a929f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ERR_NODATATYPE</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>7fc7f385ae05183005095833d19b25bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ERR_NOEXIST</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>1f4ee2fbeb4159a4f210f0b4e06b2af9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ERR_NOFILE</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>679537043a0ef5a255468d0a31ae0f35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_METADATA</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>b907d6d24b9968a5bc15389d57111bea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_DIRIDX</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>cec20b06b5e0b5f37d623922556e88f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_INDIRIDX</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>cc9828a079ac95b0b75829c0fb0551c8</anchor>
      <arglist>(m)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TABLESPACE</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>3245759aa27ae838e296a69a86d3d894</anchor>
      <arglist>(m)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBAUTOR</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>5f1423a523f50add5e2256860b41d60d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBCONTENIDO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>3506b90341d746702cbfa730fbca4be8</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBLIBRO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>422b02be0be57389c0b6c09c0c621606</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBPRESTAMO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>4867f07de08eab99b25cbafb694f8d03</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBTIPOUSUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>01d07b27d6dc4e75f791db4f1de09416</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBTITULO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>522939bc2c8663adc34bf479dcb857c9</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBUSUARIO</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>354fda162735ac639e45d73c85b06864</anchor>
      <arglist>(r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OFFSET_TBEND</name>
      <anchorfile>tipos_8h.html</anchorfile>
      <anchor>53655f0a1e3405f41b50ca1ee4b28bcf</anchor>
      <arglist>(r)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>tupla.h</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>tupla_8h</filename>
    <class kind="class">tupla</class>
  </compound>
  <compound kind="struct">
    <name>bloque_db</name>
    <filename>structbloque__db.html</filename>
    <member kind="variable">
      <type>bloque_db::@0</type>
      <name>data</name>
      <anchorfile>structbloque__db.html</anchorfile>
      <anchor>ac67d37a3dc1b7d9efb7906ceee14374</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>indice</type>
      <name>indice_indirecto</name>
      <anchorfile>unionbloque__db_1_1@0.html</anchorfile>
      <anchor>acea28e7923aeaf54d808df4ba111353</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>indice</type>
      <name>indice_directo</name>
      <anchorfile>unionbloque__db_1_1@0.html</anchorfile>
      <anchor>d04aa7711014ccfbdbec5f3102bfdc8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>tipo</name>
      <anchorfile>structbloque__db.html</anchorfile>
      <anchor>2a68da7ff214ab720a6a218abe8e82f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>borrado</name>
      <anchorfile>structbloque__db.html</anchorfile>
      <anchor>c75ef786f2eacf3265f3f3d3875a1d1d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EricleMainWindow</name>
    <filename>classEricleMainWindow.html</filename>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>bibliotecaAbrir_ArchivoAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>06277f8fac6d04a0855d8900ac7beecd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>sesion_cambiar_usuario</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>b87d612c748916acc0a17cc043ccc089</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>opcionesConfigAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>7bb39343b9388cc9cf0677e559b295cf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>fileExit</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>14396bf2b6cfc63bb3c01496abfc6515</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>finalize</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>d93dfe7196399b350e571fa3a176e489</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>saveConfig</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>1c20e0a68034c0279fc28ef4b62a5825</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>datosLibrosAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>d9bed77df457235506d002188eb17fb4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>bibliotecaIngresar_TtuloAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>c03f23dc1aede853645c7950b0d39de0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>datosAutoresAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>4be6eea9c87ca55a1713153be0939f18</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>usuariosCrearAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>6b089b1e7bc08cfddc2b0c3c56184d62</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>addLibro</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>93b83ce422b1e4569bffc57cadcd606c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>botonBuscar_released</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>9b5f839fa5d7947c19990dae6031bf7b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>buscarVer_Ventana_de_ResultadosAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>d7d6262ab8b1055e123023deb3936448</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>addTitulo</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>f963882e7421fcd6c40e4b600c2ae460</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>addAutor</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>56faba8824f2d76abc7fe4659838fce8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>VerTodosLosLibrosAction_9_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>ce918aba514179cab186be6e56cc73d0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>reportesBitcoraAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>2024e3dee526281d448efc45de260a9c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>datosEliminar_LibroAction_activated</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>c18b5acda5411937ef3a139b198e7643</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>helpContents</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>9b76102381d06793782e4202164c2e6c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot" virtualness="virtual">
      <type>virtual void</type>
      <name>helpAbout</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>6057b3357154457334020c54b1abb8ab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>saliendo</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>329004201a071c6e000e09f429b0baa1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>EricleMainWindow</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>da3bc1876da4c3eca289e493ab2ef561</anchor>
      <arglist>(QWidget *parent=0, const char *name=0)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>EricleResultWidget *</type>
      <name>erw</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>c58a281575e22d12a875539434889ac9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>database *</type>
      <name>db</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>74fc3f8eb459427bf5f7ccb4db894f99</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFileDialog *</type>
      <name>ofd</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>2f10a7f3c4dabfc192e366d4593f965d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFileDialog *</type>
      <name>cfgfd</name>
      <anchorfile>classEricleMainWindow.html</anchorfile>
      <anchor>50d08a851450e1884effe40e1c07cbd4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>indice</name>
    <filename>structindice.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>id</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>84fe1f4a331cb225f65cd91bb832090b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>tipoclave</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>f8346c7bc8881a3a08fbb88f3260a860</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>num_registro</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>27835bb3fc2e65069aad7c4e5e1104c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bloque_indice_indir</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>5e441f43078725fadd2222511cb00b03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>siguiente</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>ad0a04a6f65dec21c80eaef87b6e77ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>anterior</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>d588598a44fd84589bb7ecd88a572088</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>borrado</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>d6c82982390e22ef577b3c8a1a8013c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>esInicio</name>
      <anchorfile>structindice.html</anchorfile>
      <anchor>84713a9dbe487ecb9cfbf085cbd2f6a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>indice_directo</name>
    <filename>classindice__directo.html</filename>
    <base>indice</base>
  </compound>
  <compound kind="class">
    <name>indice_indirecto</name>
    <filename>classindice__indirecto.html</filename>
    <base>indice</base>
  </compound>
  <compound kind="class">
    <name>IndiceWrapper</name>
    <filename>classIndiceWrapper.html</filename>
    <member kind="function">
      <type></type>
      <name>IndiceWrapper</name>
      <anchorfile>classIndiceWrapper.html</anchorfile>
      <anchor>a716ab69738543e761e7864a5f67fe74</anchor>
      <arglist>(const IndiceWrapper &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IndiceWrapper</name>
      <anchorfile>classIndiceWrapper.html</anchorfile>
      <anchor>1d2f60c91fbe3ef01903e934cc3719ed</anchor>
      <arglist>(indice &amp;idx)</arglist>
    </member>
    <member kind="function">
      <type>indice</type>
      <name>getIndex</name>
      <anchorfile>classIndiceWrapper.html</anchorfile>
      <anchor>00c59fe1b5a0f545a7458e95df05f5af</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>classIndiceWrapper.html</anchorfile>
      <anchor>1054ae9ffd90f4894d93a57ec7edb264</anchor>
      <arglist>(IndiceWrapper iw)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classIndiceWrapper.html</anchorfile>
      <anchor>d0f0162fc0056f6a6d4b75d773f497ab</anchor>
      <arglist>(IndiceWrapper iw)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>linkedlist</name>
    <filename>structlinkedlist.html</filename>
    <member kind="variable">
      <type>nodo *</type>
      <name>first</name>
      <anchorfile>structlinkedlist.html</anchorfile>
      <anchor>4d7276c377258a4f3506a9ca19dfd2c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>nodo *</type>
      <name>actual</name>
      <anchorfile>structlinkedlist.html</anchorfile>
      <anchor>abaf4661e1945897fb91ed7ff132b00c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>metadata</name>
    <filename>structmetadata.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>estaGuardado</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>1af56791e34ad3c2dbbf44519de5b103</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>inicio_bloque_indice_dir</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>37a8958fdf63fe905eff776f31a6efdd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>inicio_bloque_indice_indir</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>ae97cad791645cccb3aaa1d79a1ad7cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>inicio_bloque_tablespace</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>d4790534d06615a136a299bb6fb89152</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>num_bloques_indice_dir</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>477ae1d16d09ad319be0c8b647b2bec6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>num_bloques_indice_indir</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>45d13f91294c9e72856e6d307fc78f58</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>num_bloques_tablespace</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>29785d307873e566e51c2c96ea5d4005</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>tam_crecimiento</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>e7afd531dd17d93898964cde97343037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>path_logfile</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>931912751f5bb878b05c0d9cee82fb57</anchor>
      <arglist>[255]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>path_history</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>7cfce50275d1cd27941a9e6bb02c427f</anchor>
      <arglist>[255]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>path_datafile</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>7b630571a535e411239a65fdd7eacca4</anchor>
      <arglist>[255]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>path_tmpdir</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>def86607f5078f3c9fff53d998c41adf</anchor>
      <arglist>[255]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>num_macrobloques</name>
      <anchorfile>structmetadata.html</anchorfile>
      <anchor>8845907340d07ab0c3d1b7d906c6e34c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>node</name>
    <filename>structnode.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>key</name>
      <anchorfile>structnode.html</anchorfile>
      <anchor>a1417e7fad3ebcf42dc0ec8b711f273d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>tipo</name>
      <anchorfile>structnode.html</anchorfile>
      <anchor>f6437ecd970f9e89f11c0eca2f86b09a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>data</name>
      <anchorfile>structnode.html</anchorfile>
      <anchor>e82853bbf3b0d2b71de205ae40799555</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>node *</type>
      <name>next</name>
      <anchorfile>structnode.html</anchorfile>
      <anchor>a3e8aa83f864292b5a01210f4453fcc0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>result</name>
    <filename>classresult.html</filename>
  </compound>
  <compound kind="struct">
    <name>tablespace</name>
    <filename>structtablespace.html</filename>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_autor</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>60ebdb56ab3d1a1b869b43d78f2b1d43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_contenido</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>847c6d5f3bec37501481104a64107339</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_libro</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>b034621c95fe70aef859fb2d5021e4aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_prestamo</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>1b682c942aca0b71b4350307da517238</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_tipousuario</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>f7ccb3666a85bd93142cad223626d59e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_titulo</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>4c8aaec81b68bd1664ce44b1b4b6e1f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>tam_tb_usuario</name>
      <anchorfile>structtablespace.html</anchorfile>
      <anchor>adf2cceea1b8009a8d3f90599746aca9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>tupla</name>
    <filename>classtupla.html</filename>
  </compound>
  <compound kind="dir">
    <name>/home/kreig/projects/fs/ericle/bin/</name>
    <path>/home/kreig/projects/fs/ericle/bin/</path>
    <filename>dir_7401d94b2bd7fc4b2e269d70b4f1b803.html</filename>
    <file>geninput.c</file>
  </compound>
  <compound kind="dir">
    <name>/home/kreig/projects/fs/ericle/</name>
    <path>/home/kreig/projects/fs/ericle/</path>
    <filename>dir_90fd04565074c2e9bddd5fbb0c18b513.html</filename>
    <dir>/home/kreig/projects/fs/ericle/bin/</dir>
    <dir>/home/kreig/projects/fs/ericle/src/</dir>
  </compound>
  <compound kind="dir">
    <name>/home/kreig/projects/fs/</name>
    <path>/home/kreig/projects/fs/</path>
    <filename>dir_9eaaec8421946ae9a87225ea2d46bcf9.html</filename>
    <dir>/home/kreig/projects/fs/ericle/</dir>
  </compound>
  <compound kind="dir">
    <name>/home/kreig/projects/</name>
    <path>/home/kreig/projects/</path>
    <filename>dir_cd3a2aa76173ea8af98fb5c9eece8c45.html</filename>
    <dir>/home/kreig/projects/fs/</dir>
  </compound>
  <compound kind="dir">
    <name>/home/kreig/projects/fs/ericle/src/</name>
    <path>/home/kreig/projects/fs/ericle/src/</path>
    <filename>dir_6c5092b1a1c64ce1278155b4b3dfd300.html</filename>
    <file>addUser.cpp</file>
    <file>addUser.h</file>
    <file>bloque_db.cpp</file>
    <file>bloque_db.h</file>
    <file>busquedaIsbn.cpp</file>
    <file>busquedaIsbn.h</file>
    <file>configdbdialog.cpp</file>
    <file>configdbdialog.h</file>
    <file>database.cpp</file>
    <file>database.h</file>
    <file>dataoperations.c</file>
    <file>dataoperations.h</file>
    <file>deleteLibro.cpp</file>
    <file>deleteLibro.h</file>
    <file>ericle.cpp</file>
    <file>ericle.tab.cxx</file>
    <file>ericle.tab.hxx</file>
    <file>ericle_lex.cpp</file>
    <file>ericle_yacc.cpp</file>
    <file>ericle_yacc.h</file>
    <file>ericleconfigdbdialog.cpp</file>
    <file>ericleconfigdbdialog.h</file>
    <file>ericledeletelibrodialog.cpp</file>
    <file>ericledeletelibrodialog.h</file>
    <file>ericleinsertautor.cpp</file>
    <file>ericleinsertautor.h</file>
    <file>ericleinsertlibro.cpp</file>
    <file>ericleinsertlibro.h</file>
    <file>ericleinserttitulo.cpp</file>
    <file>ericleinserttitulo.h</file>
    <file>ericlemainwindow.cpp</file>
    <file>ericlemainwindow.h</file>
    <file>ericleresultsetwidget.cpp</file>
    <file>ericleresultsetwidget.h</file>
    <file>indice.cpp</file>
    <file>indice.h</file>
    <file>indice_directo.h</file>
    <file>indice_indirecto.h</file>
    <file>indicewrapper.cpp</file>
    <file>indicewrapper.h</file>
    <file>insertAutor.cpp</file>
    <file>insertAutor.h</file>
    <file>insertLibro.cpp</file>
    <file>insertLibro.h</file>
    <file>insertTitulo.cpp</file>
    <file>insertTitulo.h</file>
    <file>lexer_lex.cpp</file>
    <file>linkedlist.c</file>
    <file>linkedlist.h</file>
    <file>logger.c</file>
    <file>logger.h</file>
    <file>login.cpp</file>
    <file>login.h</file>
    <file>mainwindow.cpp</file>
    <file>mainwindow.h</file>
    <file>metadata.c</file>
    <file>metadata.h</file>
    <file>metadata_interface.h</file>
    <file>moc_addUser.cpp</file>
    <file>moc_busquedaIsbn.cpp</file>
    <file>moc_configdbdialog.cpp</file>
    <file>moc_deleteLibro.cpp</file>
    <file>moc_ericleconfigdbdialog.cpp</file>
    <file>moc_ericledeletelibrodialog.cpp</file>
    <file>moc_ericleinsertautor.cpp</file>
    <file>moc_ericleinsertlibro.cpp</file>
    <file>moc_ericleinserttitulo.cpp</file>
    <file>moc_ericlemainwindow.cpp</file>
    <file>moc_ericleresultsetwidget.cpp</file>
    <file>moc_insertAutor.cpp</file>
    <file>moc_insertLibro.cpp</file>
    <file>moc_insertTitulo.cpp</file>
    <file>moc_login.cpp</file>
    <file>moc_mainwindow.cpp</file>
    <file>moc_modifylibro.cpp</file>
    <file>moc_ResultSetWidget.cpp</file>
    <file>modifylibro.cpp</file>
    <file>modifylibro.h</file>
    <file>r_autor.h</file>
    <file>r_contenido.h</file>
    <file>r_libro.h</file>
    <file>r_prestamo.h</file>
    <file>r_tipousuario.h</file>
    <file>r_titulo.h</file>
    <file>r_usuario.h</file>
    <file>registro.c</file>
    <file>registro.h</file>
    <file>result.cpp</file>
    <file>result.h</file>
    <file>ResultSetWidget.cpp</file>
    <file>ResultSetWidget.h</file>
    <file>resultWidget.h</file>
    <file>search_node.h</file>
    <file>searchtree.h</file>
    <file>tablespace.cpp</file>
    <file>tablespace.h</file>
    <file>tipos.h</file>
    <file>tupla.cpp</file>
    <file>tupla.h</file>
  </compound>
</tagfile>
