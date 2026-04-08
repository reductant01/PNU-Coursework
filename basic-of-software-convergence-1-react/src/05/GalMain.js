import { useState, useEffect, useRef } from "react"
import GalCard from "./GalCard";

export default function GalMain() {
  //상태변수
  const [tdata, setTdata] = useState([]);
  const [tags, setTags] = useState([]);

  const inRef = useRef();

  // 데이터 가져오기
  const getData = ((kw) => {
    let url = `https://apis.data.go.kr/B551011/PhotoGalleryService1/gallerySearchList1?`;
    url = url + `serviceKey=${process.env.REACT_APP_API_KEY}`;
    url = url + `&numOfRows=10&pageNo=1&MobileOS=ETC&MobileApp=AppTest&arrange=A`;
    url = url + `&keyword=${kw}&_type=json`;

    console.log(url)

    fetch(url)
      .then(resp => resp.json())
      .then(data => setTdata(data.response.body.items.item))

    console.log(kw);
  })

  // 제일 처음 한번
  useEffect(() => {
  }, [])

  // tdata가 변경되었을때
  useEffect(() => {
    if (tdata.length == 0) return;
    
    let tm = tdata.map(item =>
      <GalCard
        galTitle={item.galTitle}
        galWebmgalWebImageUrl={item.galWebImageUrl}
        galPhotographyLocation={item.galPhotographyLocation}
        key={item.galContentId}
      />
    )
    setTags(tm)
  }, [tdata])

  const handleClick = ((e)=>{
    e.preventDefault();
    let kw = encodeURI(inRef.current.value);
    getData(kw)
  })

  return (
    <div className='flex flex-col
                    w-full h-full'>
      <form className="w-full flex justify-center items-center m-5 ">
        <input type="text" id="txt1"
               ref={inRef}
               className="bg-blue-700 rounded text-white mr-3 p-5 text-lg" />
        <button onClick={handleClick}
                className="bg-blue-700 rounded text-white p-5 text-lg">
          확인
        </button>
      </form>
      <div className='text-black grid grid-cols-1 md:grid-cols-2 gap-4'>
        {tags}
      </div>
    </div>
  )
}
