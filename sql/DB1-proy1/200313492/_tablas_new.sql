drop table curso cascade constraint;

CREATE table "CURSO" (
    "CURSO"      NUMBER NOT NULL,
    "NOMBRE"     VARCHAR2(4000) NOT NULL,
    "CREDITOS"   NUMBER NOT NULL,
    constraint  "CURSO_PK" primary key ("CURSO")
);





drop table catedratico cascade constraint;

CREATE table "CATEDRATICO" (
    "CATEDRATICO" NUMBER NOT NULL,
    "NOMBRE"      VARCHAR2(4000) NOT NULL,
    "DIRECCION"   VARCHAR2(4000) NOT NULL,
    "TELEFONO"    NUMBER NOT NULL,
    constraint  "CATEDRATICO_PK" primary key ("CATEDRATICO")
);





drop table auxiliar cascade constraint;

CREATE table "AUXILIAR" (
    "AUXILIAR"   NUMBER NOT NULL,
    "NOMBRE"     VARCHAR2(4000) NOT NULL,
    "DIRECCION"  VARCHAR2(4000) NOT NULL,
    "TELEFONO"   NUMBER NOT NULL,
    constraint  "AUXILIAR_PK" primary key ("AUXILIAR")
);





drop table facultad cascade constraint;

CREATE table "FACULTAD" (
    "FACULTAD"   NUMBER NOT NULL,
    "NOMBRE"     VARCHAR2(4000) NOT NULL,
    constraint  "FACULTAD_PK" primary key ("FACULTAD")
);





drop table salon cascade constraint;

CREATE table "SALON" (
    "EDIFICIO"   NUMBER NOT NULL,
    "SALON"      NUMBER NOT NULL,
    "CAPACIDAD"  NUMBER NOT NULL
);

alter table "SALON" add constraint "SALON_PK"
primary key ("EDIFICIO","SALON");





drop table dia_habil cascade constraint;

CREATE table "DIA_HABIL" (
    "DIA"        NUMBER NOT NULL,
    "NOMBRE"     VARCHAR2(4000) NOT NULL,
    constraint  "DIA_HABIL_PK" primary key ("DIA")
);





drop table periodo cascade constraint;

CREATE table "PERIODO" (
    "PERIODO"     NUMBER NOT NULL,
    "HORA_INICIO" NUMBER NOT NULL,
    "HORA_FIN"    NUMBER NOT NULL,
    constraint  "PERIODO_PK" primary key ("PERIODO")
);





drop table escuela cascade constraint;

CREATE table "ESCUELA" (
    "ESCUELA"    NUMBER NOT NULL,
    "NOMBRE"     VARCHAR2(4000) NOT NULL,
    "FACULTAD"   NUMBER NOT NULL,
    constraint  "ESCUELA_PK" primary key ("ESCUELA")
);

ALTER TABLE "ESCUELA" ADD CONSTRAINT "ESCUELA_FK" 
FOREIGN KEY ("FACULTAD")
REFERENCES "FACULTAD" ("FACULTAD")
ON DELETE CASCADE;





drop table carrera cascade constraint;

CREATE table "CARRERA" (
    "CARRERA"        NUMBER NOT NULL,
    "NOMBRE"         VARCHAR2(4000) NOT NULL,
    "FECHA_CREACION" DATE NOT NULL,
    "ESCUELA"        NUMBER NOT NULL,
    "CREDITOS_CIERRE" NUMBER NOT NULL,
    constraint  "CARRERA_PK" primary key ("CARRERA")
);

ALTER TABLE "CARRERA" ADD CONSTRAINT "CARRERA_FK" 
FOREIGN KEY ("ESCUELA")
REFERENCES "ESCUELA" ("ESCUELA")
ON DELETE CASCADE;





drop table estudiante cascade constraint;

CREATE table "ESTUDIANTE" (
    "CARNET"           NUMBER NOT NULL,
    "PRIMER_NOMBRE"    VARCHAR2(4000) NOT NULL,
    "SEGUNDO_NOMBRE"   VARCHAR2(4000) NOT NULL,
    "PRIMER_APELLIDO"  VARCHAR2(4000) NOT NULL,
    "SEGUNDO_APELLIDO" VARCHAR2(4000) NOT NULL,
    "TELEFONO"         NUMBER NOT NULL,
    "DIRECCION"        VARCHAR2(4000) NOT NULL,
    "FECHA_NACIMIENTO" DATE NOT NULL,
    "INGRESO_FAMILIAR" NUMBER NOT NULL,
    "CARRERA"          NUMBER NOT NULL,
    constraint  "ESTUDIANTE_PK" primary key ("CARNET")
);

ALTER TABLE "ESTUDIANTE" ADD CONSTRAINT "ESTUDIANTE_FK" 
FOREIGN KEY ("CARRERA")
REFERENCES "CARRERA" ("CARRERA")
ON DELETE CASCADE;





drop table seccion cascade constraint;

CREATE table "SECCION" (
    "SECCION"     NUMBER NOT NULL,
    "ANIO"         NUMBER NOT NULL,
    "CICLO"       NUMBER NOT NULL,
    "CODIGO"      NUMBER NOT NULL,
    "CATEDRATICO" NUMBER NOT NULL,
    "AUXILIAR"    NUMBER NOT NULL
);

alter table "SECCION" add constraint  "SECCION_PK" primary key ("SECCION","CODIGO","ANIO","CICLO");

ALTER TABLE "SECCION" ADD CONSTRAINT "SECCION_FK" 
FOREIGN KEY ("CODIGO")
REFERENCES "CURSO" ("CURSO")
ON DELETE CASCADE;

ALTER TABLE "SECCION" ADD CONSTRAINT "SECCION_FK2" 
FOREIGN KEY ("CATEDRATICO")
REFERENCES "CATEDRATICO" ("CATEDRATICO")
ON DELETE CASCADE;

ALTER TABLE "SECCION" ADD CONSTRAINT "SECCION_FK3" 
FOREIGN KEY ("AUXILIAR")
REFERENCES "AUXILIAR" ("AUXILIAR")
ON DELETE CASCADE;





drop table plan cascade constraint;
CREATE table "PLAN" (
    "CARRERA"      NUMBER NOT NULL,
    "PLAN"         NUMBER NOT NULL,
    "ANIO_INICIO"  NUMBER NOT NULL,
    "CICLO_INICIO" NUMBER NOT NULL,
    "ANIO_FIN"     NUMBER NOT NULL,
    "CICLO_FIN"    NUMBER NOT NULL
);

alter table "PLAN" add constraint  "PLAN_PK" primary key ("CARRERA","PLAN");

ALTER TABLE "PLAN" ADD CONSTRAINT "PLAN_FK" 
FOREIGN KEY ("CARRERA")
REFERENCES "CARRERA" ("CARRERA")
ON DELETE CASCADE;





drop table asignacion cascade constraint;

create table asignacion
(
anio number not null,
ciclo number not null,
codigo number not null,
seccion number not null,
carnet number not null,
zona number not null,
nota number not null
);

alter table asignacion add constraint asignacion_pk primary key
(
ciclo,codigo,seccion,carnet,anio
);

alter table "ASIGNACION" add constraint
"ASIGNACION_FK" foreign key ("CARNET") references "ESTUDIANTE" ("CARNET");

ALTER TABLE "ASIGNACION" ADD CONSTRAINT "ASIGNACION_FK2" 
FOREIGN KEY ("ANIO","CICLO","SECCION","CODIGO")
REFERENCES "SECCION" ("SECCION","CICLO","ANIO","CODIGO")
ON DELETE CASCADE;





drop table pensum cascade constraint;

create table pensum
(
carrera number not null,
plan number not null,
codigo number not null,
creditos number not null,
creditos_prerrequisito number not null,
obligatorio number not null
);

alter table pensum add constraint pensum_pk primary key
(
carrera,plan,codigo
);

alter table "PENSUM" add constraint
"PENSUM_FK" foreign key ("CARRERA","PLAN") references "PLAN" ("CARRERA","PLAN") 
on delete cascade;

alter table "PENSUM" add constraint
"PENSUM_FK2" foreign key ("CODIGO") references "CURSO" ("CURSO") 
on delete cascade;





drop table prerrequisito cascade constraint;

create table prerrequisito
(
carrera number not null,
plan number not null,
codigo number not null,
prerrequisito number not null
);

alter table prerrequisito add constraint prerrequisito_pk primary key
(
carrera,plan,codigo,prerrequisito
);

alter table "PRERREQUISITO" add constraint
"PRERRQUISITO_FK" foreign key ("CARRERA","PLAN","CODIGO") references "PENSUM" ("CARRERA","PLAN","CODIGO") 
on delete cascade;






drop table horario cascade constraint;

create table horario
(
anio number not null,
ciclo number not null,
codigo number not null,
seccion number not null,
dia number not null,
periodo number not null,
edificio number not null,
salon number not null
);

alter table horario add constraint horario_pk primary key
(
anio,ciclo,codigo,seccion,dia,periodo
);

alter table "HORARIO" add constraint
"HORARIO_FK" foreign key ("ANIO","CICLO","CODIGO","SECCION") references "SECCION" ("ANIO","CICLO","CODIGO","SECCION") 
on delete cascade;

alter table "HORARIO" add constraint
"HORARIO_FK2" foreign key ("PERIODO") references "PERIODO" ("PERIODO") 
on delete cascade;

alter table "HORARIO" add constraint
"HORARIO_FK3" foreign key ("EDIFICIO","SALON") references "SALON" ("EDIFICIO","SALON") 
on delete cascade;

alter table "HORARIO" add constraint
"HORARIO_FK4" foreign key ("DIA") references "DIA_HABIL" ("DIA") 
on delete cascade;



drop table aprobacion cascade constraint;

CREATE table "APROBACION" (
    "PLAN"            NUMBER NOT NULL,
    "CICLO"           NUMBER NOT NULL,
    "CARRERA"         NUMBER NOT NULL,
    "ZONA_MINIMA"     NUMBER NOT NULL,
    "NOTA_APROBACION" NUMBER NOT NULL
);

alter table "APROBACION" add constraint  "APROBACION_PK" primary key ("PLAN","CICLO");

ALTER TABLE "APROBACION" ADD CONSTRAINT "APROBACION_FK" 
FOREIGN KEY ("PLAN","CARRERA")
REFERENCES "PLAN" ("PLAN","CARRERA");