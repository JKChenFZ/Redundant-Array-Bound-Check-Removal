; ModuleID = 'pre-ssa-dummy.ll'
source_filename = "dummy.c"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.13.0"

; Function Attrs: noinline nounwind ssp uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %arr = alloca [5 x i32], align 16
  store i32 0, i32* %retval, align 4
  %arrayidx = getelementptr inbounds [5 x i32], [5 x i32]* %arr, i64 0, i64 2
  store i32 1, i32* %arrayidx, align 8
  ret i32 0
}

; Function Attrs: noinline nounwind ssp uwtable
define i32 @helper() #0 {
entry:
  %retval = alloca i32, align 4
  %test = alloca i32, align 4
  %ptr = alloca i32*, align 8
  store i32 5, i32* %test, align 4
  store i32* %test, i32** %ptr, align 8
  %0 = load i32*, i32** %ptr, align 8
  store i32 6, i32* %0, align 4
  %1 = load i32, i32* %retval, align 4
  ret i32 %1
}

attributes #0 = { noinline nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 7.1.0 "}
