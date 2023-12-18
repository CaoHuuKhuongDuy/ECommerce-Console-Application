# Final Lab Project OOP - ECommerce
## Class GlobalVariable
![Logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/GlobalVariable.png)
Class này chứa các class thành viên nhằm để load các thông tin của ứng dụng.
- ListAccount: chứa các tài khoản đã đăng kí
- ListStore: chứa các cửa hàng đang hoạt động
- ListProducType: chứa các danh mục sản phẩm
- FlashSale: biến dùng để quản lý việc FlashSale 
- ListVoucher: chứa các voucher của ứng dụng
## Class ListAccount
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/listAccount.png)
ListAccount sẽ chứa một vector các Account đã được đăng ký. Các Account này sẽ được load và save vào database khi chương trình khởi chạy/kết thúc (thông qua constructor và destructor).
### Class CustomerAccount
Đây là Base class của BuyerAccount, ta tạo một base class vậy hướng tới tính mở rộng của ứng dụng. Sau này sẽ có thêm class con của CustomerAccount là SellerAccount nhằm cung cấp chương trình quản lý các cửa hàng cho người bán. 
Phương thức getPassword() và getUsername() cũng được "giấu" trong private của Base class và chỉ có ListAccount có thể truy cập nhằm xác thực thông tin đăng nhập.
## Class ListStore
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/ListStore.png)
