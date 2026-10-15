# 1. Định nghĩa thư viện tĩnh LCD1602
add_library(LED7 STATIC
    Src/led7.c
)

# 2. Khai báo thư mục Header
# PUBLIC: Bất kỳ module nào link với LCD1602 cũng sẽ tự động thấy thư mục Inc này
target_include_directories(LED7 PUBLIC 
    Inc
)

# 3. Liên kết với thư viện stm32cubemx để dùng được các hàm HAL (HAL_GPIO_WritePin, HAL_Delay...)
target_link_libraries(LED7 PUBLIC 
    stm32cubemx
)