// rfc입력후 tab입력시 자동완성
import Card from "./Card"
import CData from "./CardData.json"

export default function CardMain() {
  // const imgSrc = "./img/html.png"
  // const title = "HTML"
  // const content = "HTML(HyperText Markup Language)은 웹을 이루는 가장 기초적인 구성 요소로, 웹 콘텐츠의 의미와 구조를 정의할 때 사용"
  console.log(CData);
  const tags = CData.map((item)=> {return <Card imgSrc={item.imgUrl}
                                            key={item.title}
                                            title={item.title}
                                            content={item.content}                                          
                                            /> });

  return (
    <div className="w-10/12 grid grid-cols-1 lg:grid-cols-2 gap-4">
      {/* <Card imgSrc={imgSrc}
            title={title}
            content={content} /> */}
      {tags}     
    </div>
  )
}
