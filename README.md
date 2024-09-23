# Grafik ve Bağlantılar

Bu proje, etkileşimli bir grafik ve bağlantıları içermektedir. Aşağıda HTML kodu verilmiştir:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Interactive Graph</title>
    <style>
        .circle {
            fill: teal;
            stroke: gray;
            stroke-width: 2;
            cursor: pointer;
        }
        .circle:hover {
            fill: gray;
        }
    </style>
</head>
<body>
    <svg viewBox="0 0 500 500" width="500" height="500">
        <!-- Çemberler ve noktalar -->
        <circle cx="250" cy="250" r="200" stroke="gray" fill="none" />
        <!-- Eklenebilir küçük daireler -->
        <circle class="circle" cx="150" cy="150" r="10" onclick="window.location.href='https://example.com/link1';" />
        <circle class="circle" cx="300" cy="100" r="10" onclick="window.location.href='https://example.com/link2';" />
        <circle class="circle" cx="400" cy="300" r="10" onclick="window.location.href='https://example.com/link3';" />
        <!-- Diğer noktalar benzer şekilde -->
    </svg>
</body>
</html>
