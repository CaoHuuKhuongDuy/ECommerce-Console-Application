# Cao Hữu Khương Duy - 22127083 - 22CLC06 - Final Lab Project OOP - ECommerce application
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
ListAccount sẽ chứa một vector các Account ###đã được đăng ký. Các Account này sẽ được load và save vào database khi chương trình khởi chạy/kết thúc (thông qua constructor và destructor).
### Class CustomerAccount
Đây là Base class của BuyerAccount, ta tạo một base class vậy hướng tới tính mở rộng của ứng dụng. Sau này sẽ có thêm class con của CustomerAccount là SellerAccount nhằm cung cấp chương trình quản lý các cửa hàng cho người bán. 
Phương thức getPassword() và getUsername() cũng được "giấu" trong private của Base class và chỉ có ListAccount có thể truy cập nhằm xác thực thông tin đăng nhập.
## Class ListStore
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/ListStore.png)

ListStore là một vector chứa các class Store nhằm dễ dàng thêm / xóa khi người bán muốn đóng / mở thêm cửa hàng.
Mối quan hệ giữa chúng (A --> B : B chứa các vector A) : Product --> ListProduct --> Store --> ListStore. Biểu hiện mối tương quan logic trong thực tế.

## ListProductType
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/productType.png)
Việc quản lý mối quan hệ cha-con giữa các danh mục rất quan trọng, giúp ta dễ dàng kiểm tra voucher loại A có được dùng cho loại B hay không (được nếu B là danh mục con của A). 
Ở đây mình giả sử mối quan hệ giữa chúng tạo thành 1 rừng (biểu diễn đồ thị được thành các cây). Lúc này mình sử dụng DFS để tính được timeIn, timeOut (thời gian ra vào của một đỉnh (danh mục)). Lúc này nếu A.timeIn <= B.timeIn <= A.timeOut thì B là danh mục con của A. Vì vậy ta sẽ truy vấn được nhanh với độ phức tạp O(1).

## Các design pattern đã sử dụng
### Singleton
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/singleton.png)
### Builder
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/builder.png)
### Factory Method
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/factory.png)
### Iterator
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/iterator.png)
### State
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/state.png)
### Strategy
![logo](https://github.com/CaoHuuKhuongDuy/ECommerce-Console-Application/blob/main/image/strategy.png)


