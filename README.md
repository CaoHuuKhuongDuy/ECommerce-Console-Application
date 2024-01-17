# Cao Hữu Khương Duy - 22127083 - 22CLC06 - Final Lab Project OOP - ECommerce application
## Class GlobalVariable
![Logo](https://media.discordapp.net/attachments/1097989918694842403/1186254974884253796/GlobalVariable.png?ex=65929509&is=65802009&hm=38767928f8f4f195d72fc9defc0a54eb68bd5b0b1b2027a398b2b1368549d97c&=&format=webp&quality=lossless&width=1432&height=432)
Class này chứa các class thành viên nhằm để load các thông tin của ứng dụng.
- ListAccount: chứa các tài khoản đã đăng kí
- ListStore: chứa các cửa hàng đang hoạt động
- ListProducType: chứa các danh mục sản phẩm
- FlashSale: biến dùng để quản lý việc FlashSale 
- ListVoucher: chứa các voucher của ứng dụng
## Class ListAccount
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186255002621202513/listAccount.png?ex=65929510&is=65802010&hm=186a2c0842e41fe60a095e29e3f4d7fe3b27e82764d684434963960a1e9f1b03&=&format=webp&quality=lossless&width=942&height=698)
ListAccount sẽ chứa một vector các Account đã được đăng ký. Các Account này sẽ được load và save vào database khi chương trình khởi chạy/kết thúc (thông qua constructor và destructor).
### Class CustomerAccount
Đây là Base class của BuyerAccount, ta tạo một base class vậy hướng tới tính mở rộng của ứng dụng. Sau này sẽ có thêm class con của CustomerAccount là SellerAccount nhằm cung cấp chương trình quản lý các cửa hàng cho người bán. 
Phương thức getPassword() và getUsername() cũng được "giấu" trong private của Base class và chỉ có ListAccount có thể truy cập nhằm xác thực thông tin đăng nhập.
## Class ListStore
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254975563739136/ListStore.png?ex=65929509&is=65802009&hm=c363987b064e970a9cf9dcb1c467e636519b916697ce8c44eb9cc3e04752f9f4&=&format=webp&quality=lossless&width=336&height=698)

ListStore là một vector chứa các class Store nhằm dễ dàng thêm / xóa khi người bán muốn đóng / mở thêm cửa hàng.
Mối quan hệ giữa chúng (A --> B : B chứa các vector A) : Product --> ListProduct --> Store --> ListStore. Biểu hiện mối tương quan logic trong thực tế.

## ListProductType
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254976155140166/productType.png?ex=65929509&is=65802009&hm=caa1f08c82de3f44bfcc8084522aa94eac5630f63ba793a2461a27ccb62baad4&=&format=webp&quality=lossless&width=537&height=698)

Việc quản lý mối quan hệ cha-con giữa các danh mục rất quan trọng, giúp ta dễ dàng kiểm tra voucher loại A có được dùng cho loại B hay không (được nếu B là danh mục con của A). 
Ở đây mình giả sử mối quan hệ giữa chúng tạo thành 1 rừng (biểu diễn đồ thị được thành các cây). Lúc này mình sử dụng DFS để tính được timeIn, timeOut (thời gian ra vào của một đỉnh (danh mục)). Lúc này nếu A.timeIn <= B.timeIn <= A.timeOut thì B là danh mục con của A. Vì vậy ta sẽ truy vấn được nhanh với độ phức tạp O(1).

## Các design pattern đã sử dụng
### Singleton
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254976478097418/singleton.png?ex=65929509&is=65802009&hm=12892ad2fc7fb41b0d33c9d9852e27a3f6c5012398c158a6c4547964f6b7fbbe&=&format=webp&quality=lossless&width=707&height=523)
### Builder
![logo](https://cdn.discordapp.com/attachments/1097989918694842403/1186254649477574737/builder.png?ex=659294bb&is=65801fbb&hm=e91a223b753c045be8e8f7ee223c8b1362623c0caba1d7f1d3d261d783194227&)
### Factory Method
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254974364172298/factory.png?ex=65929509&is=65802009&hm=8fe63b8ac72e666f88e01bd7803ee9b8c850d2ff72bdf33e2a9b143a9a65ab99&=&format=webp&quality=lossless&width=1432&height=190)
### Iterator
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254975236587550/iterator.png?ex=65929509&is=65802009&hm=477e77fd0dc8bf7bd7e1deb650b254d8e1aa02808283d3872630e1b3aee557a0&=&format=webp&quality=lossless&width=878&height=222)
### State
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186255002893828136/state.png?ex=65929510&is=65802010&hm=50148761ddacd2818aafd470d170824d666a1e56220ec87000262f18274d0284&=&format=webp&quality=lossless&width=975&height=698)
### Strategy
![logo](https://media.discordapp.net/attachments/1097989918694842403/1186254976763301978/strategy.png?ex=6592950a&is=6580200a&hm=fbe58297134e1807b5e35a3676fdc27e66a4b75583d0a676d280c27ad5009d2b&=&format=webp&quality=lossless&width=750&height=292)

## Khả năng mở rộng cửa dự án
1. Tạo thêm class SellerAccount, cung cấp trình quản lý cho seller.
2. Không sử dụng Singleton đối với ShoppingCart và lưu thêm giỏ hàng vào data của người dùng khi người dùng thoát ứng dụng.
