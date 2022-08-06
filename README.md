# MFC Standard Calculator

## 1. Chức năng

#### Chức năng yêu cầu
- Standard Calculator cung cấp các phép toán cơ bản, nhận lệnh và tính toán ngay khi chúng được nhập vào.
- Cung cấp các biến nhớ (MR, MS, MC, M+, M-).
- Hiển thị lịch sử tính toán và cho phép chỉnh sửa lịch sử (chỉ hỗ trợ các phép tính đơn giản): <br>

#### Chức năng thêm
- Cung cấp thêm chức năng tính sin, cos, tan, log, ln (có thể sử dụng cùng với các phép toán cơ bản).

## 2. Flow cơ bản:

#### Người dùng thực hiện các phép tính cơ bản (cộng, trừ, nhân, chia): 
    1, Người dùng nhập toán hạng thứ nhất. 
    2, Người dùng nhập toán tử. 
    3, Người dùng nhập toán hạng thứ 2. 
    4, Người dùng nhấn "=". 
    5, Kết quả được hiển thị trên màn hình và được thêm vào cuối của history panel. 
    6, Nếu sau đó người dùng tiếp tục ấn "=" mà không nhập thêm số nào thì sẽ tiếp tục thực hiện phép tính được thực hiện ngay trước đó.

#### Người dùng sử dụng dấu thập phân "." (comma): 
    1, Nếu chưa có dấu "." nào thì thêm dấu chấm. 
    2, Nếu có rồi thì bỏ qua (đảm bảo chỉ có 1 dấu ".").

#### Người dùng thực hiện các phép toán square root (sqrt), inverse (1/x), sin, cos, tan, log, ln: 
    1, Nếu các phép toán đó được thực hiện 1 cách độc lập (không đi kèm các phép toán cơ bản) thì chỉ cần ấn nút tương ứng với toán tử đó là sẽ cho ra kết quả. <br>
    2, Nếu sử dụng cùng các phép toán khác thì phải ấn dấu "=".

#### Người dùng muốn edit lịch sử tính toán (chỉ hỗ trợ các phép tính cộng, trừ, nhân, chia): 
    1, Sử dụng mũi tên "🡡", "🡣" để đi đến vị trí muốn chỉnh sửa (default là vị trí cuối cùng). 
    2, Người dùng ấn nút "Edit" để chỉnh sửa. <br>
    3, Người dùng nhập phép toán mới (nhập bằng bàn phím). <br>
    4, Người dùng ấn nút "Recalculate" để thực hiện lại phép toán. <br>
    5, Kết quả được update tại vị trí được chọn trên history panel. <br>
    6, Lưu ý nếu không nhấn "Recalculate" mà nhấn Enter thì sẽ không thực hiện lại phép toán đó.

## 3. Event-Driven:

#### Event-Driven (kiến trúc hướng sự kiện) là mô hình mà sự giao tiếp, xử lý của các events là yếu tố cốt lõi (khác với mô hình request-response).

#### Ưu điểm của Event-Driven: 
    1, Cho phép phân tách các thành phần (không còn phụ thuộc vào nhau). 
    2, Có khả năng mở rộng tốt hơn. 
    3, More flexibility and robustness. 
    4, Các sự kiện có thể được xử lý cùng lúc. 
    5, No single point of failure.

#### Nhược điểm: 
    1, Hiệu năng kém hơn do phải giao tiếp qua bên trung gian (Broker). 
    2, Độ phức tạp cao hơn do phải theo dõi từng event. 
    3, Truyền thông qua Broker nên sẽ có độ trễ.

#### Mô hình Event-Driven trong project này: 
    1, Mỗi lần nhấn chuột hay keystroke được tính là 1 event. 
    2, Các event này sẽ được xử lý 1 cách độc lập bởi từng function. 
    3, Người dùng là người tạo ra event (event producer). 
    4, Các function là Broker (event handler). 
    5, Kết quả hiện trên màn hình là event consumer. <br>

 
