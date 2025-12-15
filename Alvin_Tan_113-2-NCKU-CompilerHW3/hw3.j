.source Main.j
.class public Main
.super java/lang/Object

.method public <init>()V
aload_0
invokespecial java/lang/Object/<init>()V
return
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
ldc 1
istore 1
For_0:
ldc 101
istore 2
iload 1
iload 2
if_icmplt Ltrue0
iconst_0
goto Lend0
Ltrue0:
iconst_1
Lend0:
istore 3
iload 3
ifeq Exit_1
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/println(I)V
ldc 1
istore 4
iload 1
iload 4
iadd
istore 1
goto For_0
Exit_1:
return
.end method
