@echo off
chcp 65001 > nul
setlocal enabledelayedexpoution

echo 编译程序中...

g++ -std=c++20 -O2 -o std.exe std.cpp
if not %errorlevel% == 0 (
    echo std.cpp 编译失败
    pause
    exit /b 1
)

g++ -std=c++20 -O2 -o std_b.exe std_b.cpp
if not %errorlevel% == 0 (
    echo std_b.cpp 编译失败
    pause
    exit /b 1
)

echo 编译成功
echo 生成所有测试点答案...

for /l %%i in (1,1,20) do (
    if exist "%%i.in" (
        std.exe < "%%i.in" > "%%i.out"
        echo 生成 %%i.out
    ) else (
        echo 警告: %%i.in 不存在
    )
)

echo 答案生成完成
echo 开始对拍前10组测试点...

set passed=0
set failed=0

for /l %%i in (1,1,10) do (
    if exist "%%i.in" (
        std_b.exe < "%%i.in" > "std_b_%%i.out"
        fc "%%i.out" "std_b_%%i.out" > nul
        if not errorlevel 1 (
            echo 测试点 %%i: 通过
            set /a passed+=1
            del "std_b_%%i.out" 2>nul
        ) else (
            echo 测试点 %%i: 失败
            fc "%%i.out" "std_b_%%i.out"
            set /a failed+=1
        )
    ) else (
        echo 跳过: %%i.in 不存在
    )
)

echo.
echo 对拍结果:
echo 通过: !passed!
echo 失败: !failed!

if !failed! == 0 (
    echo 所有测试点对拍通过！
) else (
    echo 有 !failed! 个测试点未通过
)

pause