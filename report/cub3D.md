# cub3D

## MY first RayCaster with miniLibX

> 요약 : 이 프로젝트는 세계적으로 인기 있었던, 최초의 FPS였던 90년대 게임에 영감을 받았다.  
> 이 프로젝트는 당신에게 Ray-casting을 탐험할 수 있도록 해 줄 것이다.  
> 당신의 목표는 미로 안에서 동적인 시각을 가지는 것, 그럼으로써 답을 찾는 것이다.

### Chapter I

Uber로 유명한(?) John Carmack과 John Romero에 의해 설립된 Id Software에 의해 제작됐고,  
1992년 Apogee Software에 의해 발행된 Wolfenstein 3D는 1인칭 슈팅 비디오 게임의 시초이다.

Wolfenstein 3D는 Doom(Id Software, 1993), Doom II(Id Software, 1994), Duke Nukem 3D(3D Realm, 1996),  
그리고 Quake(Id Software, 1996)와 같이 비디오 게임 역사 상 획기적인 게임들의 조상과도 같은 게임이다.

이제, 당신이 역사를 쓸 차례다...

### Chapter II

### 목표

이번 프로젝트의 목표는 여지껏 했던 과제의 목표와 비슷하다  
: 꼼꼼함, C를 쓰는 것, 기본적인 알고리즘을 쓰는 것, 정보를 검색하는 것 등등..

그래픽 디자인 프로젝트인 만큼, cub3D는 다음과 같은 영역에서의 발전을 가져다 줄 것이다.  
: 윈도우, 색상, 이벤트, 도형 채우기 등등.

결론적으로 말해 cub3D는 (너무) 구체적인 이해 없이 수학을 적용하면서 즐길 수 있는 놀이터가 될 것이다.

인터넷에 떠돌아다니는 많은 문서자료들로, 우아하고 효율적인 알고리즘을 만들기 위한 도구로서  
수학을 사용하게 될 것이다.

과제를 시작하기 이전에 다음 사이트에서 게임을 즐겨볼 것을 권장한다  
:[http://users.atw.hu/wolf3d/](http://users.atw.hu/wolf3d/)

### Chapter III

### Common Instructions

-   Makefile에는 $(NAME), all, clean, fclean 그리고 re가 수행될 수 있도록 하기.
-   Libft사용가능.

### Chapter IV

### 필수 파트 - cub3D

-   프로그램명 - cub3D
    
-   제출 파일 - 모든 파일
    
-   Makefile - all, clean, fclean, re, bonus
    
-   전달 인자 - \*.cub 포맷 내의 맵
    
-   허용 함수
    
-   open, close, read, write, malloc, free, perror, strerror, exit
    
-   math 라이브러리가 허용하는 모든 함수
    
-   MinilibX에 있는 모든 함수
    
-   Libft 사용가능여부 : Yes
    

#### 설명

-   미로 속 "현실적인" 3D 그래픽의 1인칭 시점을 만들어라.
    
-   앞서 언급한 Ray-Casting을 이용해 만들어보라.
    
-   조심할 것
    
-   miniLibX를 사용해야 한다. OS 시스템에서 이용가능한 것 혹은 그 소스 말이다.
    
-   소스로 작업하기로 결정했다면, libft 규칙과 똑같은 룰을 따라야 한다.
    
-   창(window) 관리는 매끄럽게 이루어져야 한다 : 다른 윈도우로 전환, 최소화 등에서도.
    
-   동 서 남 북 벽면의 텍스쳐(질감)를 다르게 바꿔보라.(이는 당신의 선택이다.)
    
-   당신의 프로그램은 벽 대신 아이템을 표시할 수 있어야 한다.
    
-   천장과 바닥 색은 달라야 한다.
    
-   Deethought가 당신의 프로젝트를 평가할 때, 프로그램의 두 번째 인자가 "--save"인 경우
    
-   당신의 프로젝트는 처음으로 변환된 이미지를
    
-   bmp 포맷으로 저장해야 한다.
    
-   두 번째 인자가 없는 경우, 프로그램은 이미지를 창(window)에 띄워야 하고, 다음 규칙을 지켜야 한다 :
    
    -   좌우 방향키는 좌우를 바라보는 역할을 할 수 있도록 할 것.
    -   W, A, S, D 키는 미로의 관점에서 당신이 움직이도록 할 것.
    -   ESC 키는 program을 깨끗하게 종료시키고 창을 닫도록 할 것.
    -   윈도우 프레임의 빨간색 십자선을 클릭하는 것은 윈도우를 닫고 프로그램을 깨끗이 종료시키도록 할 것.
    -   맵 내 선언한 스크린의 크기가 허용범위 이상인 경우, 창의 크기는 현재를 기준으로 설정되야 한다.
    -   minilibX 내에 있는 이미지를 사용할 것을 매우 권장한다.
-   당신의 프로그램은 .cub 확장자로 첫 번째 인자를 화면 표현 방식(a scene description)으로 받아야 한다.
    
    -   map은 4개의 글자로만 구성되어 있다 :
        
        -   0 : 비어 있는 공백(empty space)
        -   1 : 벽
        -   2 : 아이템
        -   그리고 플레이어의 시작 위치와 스폰 위치(spawning orientation)  
            ex)  
            [##_Image|kage@bPeZOw/btqCy5xVHx8/GkPLVETu37xvypSvwsWkn1/img.png|alignCenter|data-origin-width="658" data-origin-height="86" width="100%"|||_##]
    -   map은 닫혀 있거나 벽으로 둘러싸여 있어야 하며, 그게 아니면 프로그램은 에러를 반환해야 한다.
        
    -   맵 요소 외에는, 각각의 요소들이 하나 혹은 그 이상의 Empty line(공백 줄)로 구분돼야 한다.
        
    -   마지막에 있어야 하는 맵 요소 외에는, 각각의 요소들이 어떤 order(정렬방식)으로도 파일 안에 세팅될 수 있다.
        
    -   맵은 파일 내에서 보이는 것고 가타이 parse되어야 한다. 공백은 유효한 형식이며, 그 처리는 당신에게 달려있다.
        
    -   규칙을 지키는 어떤 종류의 맵도 parse할 수 있어야 한다.
        
    -   맵을 제외한 각각의 요소는 identifier정보로 시작한다(1개 또는 2개의 문자로 구성된),
        
    -   그 뒤의 구체적인 정보는 다음과 같은 엄격한 규칙을 따른다 :
        
        #### Resolution :
        
        -   R 1920 1080
            
        -   identifier : R
            
        -   x render size
            
        -   y render size
            

```
    #### North texture(북쪽 질감) :

    -   NO ./path\_to\_the\_north\_texture

    -   identifier : NO

    -   path to the north texture


    #### South texture :

    -   SO ./path\_to\_the\_south\_texture

    -   identifier : SO

    -   path to the south texture


    #### West texture :

    -   WE ./path\_to\_the\_west\_texture

    -   identifier : WE

    -   path to the west texture


    #### East texture :

    -   EA ./path\_to\_the\_east\_texture

    -   identifier : EA

    -   path to the east texture


    #### Floor color :

    -   F 220, 100, 0

    -   identifier : F

    -   R, G, B colors in range \[0, 255\] : 0, 255, 255


    #### Ceiling color :

    -   C 225, 30, 0

    -   identifier : C

    -   R, G, B colors in range \[0, 255\] : 0, 255, 255

    -   ex)  
        sky box menain
```

[##_Image|kage@bdmJSX/btqCB7VC34k/R4QUgVZXE5HNGlgg8nNgFk/img.png|alignCenter|data-origin-width="654" data-origin-height="390" width="100%"|||_##]

```

    -   파일에서 잘못된 구성을 만날 경우 프로그램은 exit되어야 하며 "Error\\n"을 반환해야 한다.

    -   Error\\n 뒤에는 직접 설정한 메시지가 나올 수 있다.
```

### Chapter V

필수 파트가 완벽한 경우에만 보너스 파트가 채점된다.  
완벽하다는 의미는 자잘한 실수에 대해서도 잘 처리돼야 한다는 뜻이다.  
평가받을 때 필수 파트에서 모든 점수를 받을 때만 보너스 파트가 채점된다.  
그렇지 않으면 보너스 파트는 모조리 무시될 것이다.

-   보너스 리스트 :
    
    -   벽 무너짐
    -   보이지 않는 천장(a skybox)
    -   바닥이나 천장의 질감
    -   HUD(Heads Up Display) - 플레이어의 상태나 방어구 내구도 등 표시하는 것.
    -   천장과 바닥을 바라볼 수 있는 기능
    -   점프하거나 앉기 기능
    -   거리에 기반한 그림자 이펙트
    -   체력 바(bar)
    -   미로 속의 더 많은 아이템
    -   오브젝트 파괴
    -   오브젝트 또는 트랩을 주움으로써 포인트를 얻거나 체력을 잃도록 만들기
    -   여닫을 수 있는 문
    -   비밀 문
    -   총 발사 애니메이션 or animated sprite
    -   여러 개의 레벨
    -   사운드이펙트, 배경음악
    -   마우스로 시점 전환하기
    -   무기와 싸울 수 있는 악당!
-   Bonus Part
-   팁 : 모든 보너스 점수를 얻으려면 14개를 클리어해야 한다. 시간 날리지 않도록 주의!
-   information
-   보너스 파트를 완성하기 위해 다른 함수를 이용할 수 있다. (그 함수가 평가 동안 합리적인 경우에만)
-   장면(Scene) 파일 포맷을 바꿀 수 있다.



그림이 안 보인다면 :

[https://42kchoi.tistory.com/19?category=886844](https://42kchoi.tistory.com/19?category=886844)