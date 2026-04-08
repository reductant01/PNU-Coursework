import { useState, useEffect, useRef } from "react"

export default function Final() {
  //상태변수
  const [tdata, setTdata] = useState([]);
  const [tags, setTags] = useState([]);
  const [selMv, setSelMv] = useState("");

  const inRef = useRef();

  // 데이터 가져오기
  const getData = ((kw) => {
    let tmDt = inRef.current.value.replaceAll("-", "")
    let url = `https://apis.data.go.kr/6260000/DailyWaterQualityService/cleanWaterQualityDetail?`;
    url = url + `serviceKey=${process.env.REACT_APP_API_KEY}`;
    url = url + `&pageNo=1&numOfRows=12&`;
    url = url + `argDate=20240715&resultType=json`;

    // console.log(url)

    fetch(url)
      .then(resp => resp.json())
      .then(data => setTdata(data.cleanWaterQualityDetail.body.items.item))
  })

  // 제일 처음 한번
  useEffect(() => {
  }, [])


  // 날짜가 선택되었을 때
  const handleSelDt = ((e) => {
    e.preventDefault();
    console.log(inRef.current.value)
    getData();
  })

  // 컴포넌트 생성시
  useEffect(() => {

  }, []);

  // tdata가 변경될때 실행
  useEffect(() => {
    if (tdata.length == 0) return;

    console.log(tdata)
    let tm = tdata.map(item =>
      <div>
        <div className="h-full text-sm bg-white border border-gray-200 rounded-lg shadow 
                        flex flex-col p-5" 
        key={item.cwGroupNm}>
          <div className="m-1 font-bold">
            {item.cwGroupNm}
          </div>
          <div className="m-1 font-bold text-green-500">
            {`${item.inspIemNm1} ( ${item.inspWqbs} )`}
          </div>
          <div className="grid grid-cols-2 gap-4 
                            ">
            <div className="flex justify-center items-center
                              border rounded-lg
                              bg-blue-700
                              h-8 ">
              <div className="text-white mr-2">
                {`명장검사`}
              </div>
              <div className="text-yellow-200 font-bold text-sm">
                {item.mjValue}
              </div>
            </div>
            <div className="flex justify-center items-center
                              border rounded-lg
                              bg-blue-700
                              h-8 ">
              <div className="text-white mr-2">
                {`범어사검사`}
              </div>
              <div className="text-yellow-200 font-bold text-sm">
                {item.buValue}
              </div>
            </div>
            <div className="flex justify-center items-center
                              border rounded-lg
                              bg-blue-700
                              h-8 ">
              <div className="text-white mr-2">
                {`화명검사`}
              </div>
              <div className="text-yellow-200 font-bold text-sm">
                {item.hmValue}
              </div>
            </div>
            <div className="flex justify-center items-center
                              border rounded-lg
                              bg-blue-700
                              h-8 ">
              <div className="text-white mr-2">
                {`덕산검사`}
              </div>
              <div className="text-yellow-200 font-bold text-sm">
                {item.dsValue}
              </div>
            </div>
          </div>
        </div>
      </div>

    )
    setTags(tm);

  }, [tdata]);

  return (
    <div className="h-full
                    text-black w-10/12
                    relative overflow-x-auto sm:rounded-lg
                    ">
      <form className="flex justify-end items-center
                       mb-2
                       text-lg">
        <label htmlFor="dt" className="text-sm mr-5 font-bold">
          날짜선택
        </label>
        <input type="date" id="dt"
          ref={inRef} // input에 ref 속성주기
          onChange={handleSelDt}
          className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block ps-10 p-2.5 " />
      </form>

      <div className='text-black grid grid-cols-3 gap-4'>
        {tags}
      </div>


    </div>
  )
}